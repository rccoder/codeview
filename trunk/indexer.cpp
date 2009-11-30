#include <QtCore/QEventLoop>
#include <QtCore/QString>
#include <QtCore/QDir>

#include <QtGui/QMessageBox>


#include "indexer.h"

#define  BUFSIZE   128
#define MAX_LINE_NUM  1024

Indexer::Indexer()
{
	state = 0;
}

void Indexer::ctrl_search(string result,vector<string> &path)
{
	unsigned int i;

	ProcessDialog1 *p1 = new ProcessDialog1;

	p1->m_ui->progressBar->setMaximum (path.size());
	p1->m_ui->progressBar->setMinimum (0);
	p1->show();

	for ( i = 0; i < path.size(); i++ )
	{
		p1->m_ui->progressBar->setValue(i + 1);
		p1->m_ui->label->setText("正在处理文件:" + QString(path.at(i).c_str()));
		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);
		lexan(path.at(i), i );/*识别标识符、关键字*/
	}
	p1->close();
	delete p1;

	ct(result,simple,0);
	ct(result,sc,1);
	ct(result,func,2);
}

void Indexer::lexan( string source, int file_no )
{
	char t;/*读入的字符*/
	int lineno = 0, rowno = 0;/*目前所在行*/
	char lexbuf[BUFSIZE];/*字符缓冲区*/
	char s[MAX_LINE_NUM];/*读取文本中的一行*/
	int len, flag;

	FILE *fin = fopen( source.c_str(), "r" );/*以只读的方式打开文件*/

	if ( fin == NULL )/*错误处理*/
	{
		 QMessageBox::information(0, "无法打开文件", QString(source.c_str()));
		return ;
	}


	while (1)/*一直处于读状态*/
	{
		if (  fgets( s, MAX_LINE_NUM, fin ) != NULL )
		{
			lineno++;/*行坐标*/
			len = strlen( s );
			for ( rowno = 0; rowno < strlen( s ); rowno++ )
			{
				t = s[rowno];
				if ( t == ' ' || t == '\t' ) /*去掉空白字符*/
					;
				else if ( isalpha( t ) || t == '_' )/*t是字母或者是下划线*/
				{
					recogid( fin,lexbuf,t,&rowno,s,&lineno, file_no );   /*识别关键字和标识符*/

				}
				else if ( t == '#' )/*读到了宏或头文件*/
					break;/*忽略这行*/
				else if ( t == '/' )/*去掉注释*/
				{
					flag = del_mess( fin,&rowno,s ,&lineno);
					if ( flag == 0 )
						break;
					else if ( flag == 1 )
						continue;
				}
				else if ( t == '\'' )/* 去掉字符 如'A'*/
					del_char( &rowno,s );
				else if ( t == '\"' )/*去掉“”内的字符*/
					del_const_str( fin, &rowno, s, &lineno );
				else if ( t == ';' || t == '{' )
					state = 0;
			}
		}
		else
			break;
	}

	fclose( fin );/*关闭文件*/
}


int Indexer::iskeyWord( char *lexbuf )
{
	char *keyWord[]={  "and",             "and_eq",        "asm",               "auto",          "bitand",        "bitor",
					   "bool",            "break",         "case",              "catch",         "char",          "class",
					   "compl",           "const",         "const_cast",        "continue",      "default",       "delete",
					   "do",              "double",        "dynamic_cast",      "else",          "enum",          "explicit",
					   "export",          "extern",        "false",             "float",         "for",           "friend",
					   "goto",            "if",            "inline",            "int",           "long",          "mutable",
					   "namespace",       "new",           "not",               "not_eq",        "operator",      "or",
					   "or_eq",           "private",       "protected",         "public",        "register",      "reinterpret_cast",
					   "return",          "short",         "signed",            "sizeof",        "static",        "static_cast",
					   "struct",          "switch",        "template",          "this",          "throw",         "true",
					   "try",             "typedef",       "typeid",            "typename",      "union",         "unsigned",
					   "using",           "virtual",       "void",              "volatile",      "wchar_t",       "while",
					   "xor",             "xor_eq"
				   };

	int i;

	for ( i = 0; i < 74 ; i++ )
	{
		if (strcmp("class",lexbuf) == 0 )
			state = 2;
		if (strcmp("struct",lexbuf) == 0 )
			state = 1;
		if ( strcmp(keyWord[i],lexbuf) == 0 )
			return 1;
	}

	return 0;
}


//首先此行识别一个单词，处理他。等待主调函数对此行的下一次调用。
void Indexer::recogid( FILE* fin,char *lexbuf,char ch, int *rowno,char *s,int *lineno,int file_no )
{
	int index = 0;/*回到缓冲区第一个位置*/
	char t;
	t = ch;
	int flag;
	/**********************************************************************/
	temp a;
	/**********************************************************************/

	while ( isalnum( t ) || t == '_'  )/*t是字母或是数字或是下划线*/
	{
		lexbuf[index] = s[*rowno];
		index = index + 1;
		(*rowno)++;
		t =  s[*rowno];
	}
	lexbuf[index] = '\0';/*加入结束标志*/
	(*rowno)--;/*回退*/

	/**********************************************************************/
	if ( iskeyWord( lexbuf ) == 0 )
	{
		flag= is_key_type( fin ,lexbuf, rowno, s,lineno );
		if ( flag == 3 )
		{
			a.file_no = file_no;
			a.idf  = lexbuf;
			a.idf_row = f_lineno;
			//fprintf( fout_func, "%s\t%d\t%d\n", lexbuf,f_lineno,file_no );
			func.push_back( a );
		}
		else if ( flag == 0 )
		{
			a.file_no = file_no;
			a.idf  = lexbuf;
			a.idf_row = *lineno;
			if ( state == 1 || state== 2 )
			{
				//fprintf( fout_struct, "%s\t%d\t%d\n", lexbuf,*lineno,file_no );
				sc.push_back( a );
				state = 0;
			}
			else
				// fprintf( fout_simple, "%s\t%d\t%d\n", lexbuf,*lineno,file_no );
				simple.push_back( a );

		}
	}
	/**********************************************************************/
}

int Indexer::del_mess( FILE* fin, int *rowno,char *s,int *lineno )
{
	char t;
	(*rowno)++;
	t = s[*rowno];


	if ( t == '/' )
		return 0;
	else if ( t == '*' )
	{
		while (1)
		{
			(*rowno)++;
			t = s[*rowno];
			while ( !(t == '\0' || t == '*') )
			{
				(*rowno)++;
				t = s[*rowno];
			}
			if ( t == '\0' )
			{
				fgets( s, MAX_LINE_NUM, fin );
				(*lineno)++;
				*rowno = -1;
			}
			else if ( t == '*' )
			{
				(*rowno)++;
				t = s[*rowno];

				if ( t == '/' )
					return 1;
				else if ( t == '*' )
					(*rowno)--;
			}
		}

	}
}


void Indexer::del_char( int *rowno,char *s )
{
	char t;
	while ( 1 )
	{
		t = s[*rowno];
		(*rowno)++;
		if ( t == '\\' )
		{
			t = s[*rowno];
			(*rowno)++;
		}
		else if ( t == '\'' )
			break;
	}
}


void Indexer::del_const_str( FILE* fin,int *rowno,char *s,int *lineno )
{
	char t;
	while ( 1 )
	{
		(*rowno)++;
		t = s[*rowno];

		while ( !(t == '\0' || t == '\"') )
		{
			(*rowno)++;
			t = s[*rowno];
		}
		if ( t == '\0' )
		{
			fgets( s, MAX_LINE_NUM, fin );
			(*lineno)++;
			*rowno = -1;
		}
		else if ( t == '\"' )
			break;
	}
}
/**
*识别标识符的类型，使用state来表征，state取不同的值代表不同的类型
*0——简单
*1——结构体
*2——类
*3——函数
**/
int Indexer::is_key_type( FILE* fin,char *lexbuf, int *rowno, char *s ,int *lineno)
{
	int count = 0;
	char t;
	int flag = 0;//1代表遇到（，2代表遇到了），3代表遇到了{

	if ( strcmp ( "struct", lexbuf ) == 0 )
	{
		state = 1;
		return 1;/*是结构体*/
	}
	else if ( strcmp ( "class", lexbuf ) == 0 )
	{
		state = 2;
		return 2;/*是类*/
	}
	else if ( iskeyWord( lexbuf ) == 0 )///*不是关键字*/ /*需要向后看，判断是不是函数*/
	{
		(*rowno)++;
		t = s[*rowno];
		f_lineno = *lineno;

		while ( t == ' ' || t == '\t' )//跳过空白字符
		{
			(*rowno)++;
			count++;
			t = s[*rowno];
		}
		if ( t == '(' )//读到（只能说明可能是函数
		{
			flag = 1;
			(*rowno)++;
			count++;
			t = s[*rowno];

			while ( t != ')' && t != '\0' )//读到下一个右括号
			{
				(*rowno)++;
				count++;
				t = s[*rowno];
				if ( t == ')' )
				{
					flag = 2;
					break;
				}
				else if ( t== '\0' )
				{
					if (fgets( s, MAX_LINE_NUM, fin ) == NULL)
						return 0;
					(*lineno)++;
					(*rowno) = 0;
					t = s[*rowno];
				}
			}

			if ( t == ')' )
			{//看后边第一个非空白字符，若为{则是函数名
				(*rowno)++;
				count++;
				t = s[*rowno];
				while ( t == ' ' || t == '\t' || t == '\n' )//跳过空白字符
				{
					if ( t == '\n' )
					{
						if (fgets( s, MAX_LINE_NUM, fin ) == NULL)
							return 0;
						(*lineno)++;
						(*rowno) = 0;
						t = s[*rowno];
					}
					else
					{
						(*rowno)++;
						count++;
						t = s[*rowno];
					}
				}
				if ( t == '{' )
					return 3;
				else if ( t == ':' )//考虑了c++中的类成员的初始化
					return 3;
				else
					return 0;
			}
		}
		else
			return 0;//标识符后不是（，返回0，即不是函数。
	}
	else
		return 0;
}

int Indexer::ct( string path,vector <temp> rudiment, int flag )
{
	string id;
	int present_path_id;
	int r;

	if ((flag < 0) || (flag > 2)) return 1;

	ProcessDialog1 *p1 = new ProcessDialog1;

	p1->m_ui->progressBar->setMaximum (rudiment.size());
	p1->m_ui->progressBar->setMinimum (0);
	if(flag == 0)
		p1->m_ui->label->setText("正在处理普通标示符");
	else if(flag == 1)
		p1->m_ui->label->setText("正在处理类和结构标示符");
	else if(flag == 2)
		p1->m_ui->label->setText("正在处理函数标示符");
	p1->show();

	for (int j = 0;j < (int)rudiment.size();j++)
	{
		p1->m_ui->progressBar->setValue(j + 1);
		qApp->processEvents(QEventLoop::ExcludeUserInputEvents);

		present_path_id = rudiment[j].file_no;
		r = rudiment[j].idf_row;
		id = rudiment[j].idf;

		int tag = 0;

		for (int i = 0;i < (int)index[flag].size();i++)
		{
			if (id == index[flag][i].identifier)
			{
				struct chain c;
				c.path_id = present_path_id;
				c.row = r;
				index[flag][i].path.push_back(c);
				tag = 1;
				break;
			}
		}

		if (tag == 0)
		{
			struct item ele;
			ele.identifier = id;

			struct chain c;
			c.path_id = present_path_id;
			c.row = r;

			ele.path.push_back(c);
			index[flag].push_back(ele);
		}
	}
	p1->close();
	delete p1;
	FILE *T;

	if (flag == 0) T = fopen((path + QDir::separator().toAscii() +"simple.txt").c_str(),"w");
	else if (flag == 1) T = fopen((path + QDir::separator().toAscii() +"struct.txt").c_str(),"w");
	else T = fopen((path + QDir::separator().toAscii() +"func.txt").c_str(),"w");

	if (T == NULL) return 1;

	for (int i = 0;i < (int)index[flag].size();i++)
	{
		fprintf(T,"%s\t%d\t",index[flag][i].identifier.c_str(),index[flag][i].path.size());
		for (int j = 0;j < (int)index[flag][i].path.size();j++)
		{
			fprintf(T,"%d\t%d\t",index[flag][i].path[j].path_id,index[flag][i].path[j].row);
		}
		fprintf(T,"\n");
	}
	fclose(T);

	return 0;
}
