#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cctype>
#include "struct.h"
#include "ui_processdialog1.h"
#include "processdialog1.h"

using namespace std;

class Indexer {
public:
	Indexer();
	void ctrl_search( string result,vector<string> &path );

private:
	int iskeyWord( char *lexbuf );
	void recogid( FILE* fin,char *lexbuf,char ch, int *rowno,char *s,int *lineno, int file_no );
	int del_mess( FILE* fin, int *rowno,char *s,int *lineno );
	void del_char( int *rowno,char *s );
	void del_const_str( FILE* fp2, int *rowno,char *s,int *lineno );
	int is_key_type( FILE* fp,char *lexbuf, int *rowno, char *s ,int *lineno);
	void lexan( string source, int file_no );

	int ct(string,vector<temp> b,int a);

	int state;
	int f_lineno;

	vector<temp> simple;//存放简单变量的向量
	vector<temp> sc;//存放类和结构体的向量
	vector<temp> func;//存放函数的向量

	vector <item> index[3];
};

#endif // INDEXER_H
