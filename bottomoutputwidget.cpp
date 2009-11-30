#include "bottomoutputwidget.h"
#include "ui_bottomoutputwidget.h"

#define LINE_TO_VIEW 6

#include <QtCore/QTextStream>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QRegExp>

#include <QtGui/QMessageBox>
#include <QtGui/QScrollBar>

#include <stdio.h>

extern vector <QString> pathInFile;//没有经过排序的
QString oslabPath = "..";

BottomOutputWidget::BottomOutputWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::BottomOutputWidget)
{
	m_ui->setupUi(this);

	oslabPath = QDir(oslabPath).absolutePath();
	
	connect(m_ui->checkBoxDef, SIGNAL(clicked()),
			this, SLOT(defOrNotText()));
	connect(m_ui->label, SIGNAL(linkActivated ( const QString &)),
			this, SIGNAL(labelLinkClicked( const QString &)));
	
	process_clean = new QProcess(this);
	process_make = new QProcess(this);
	process_mount = new QProcess(this);
	process_umount = new QProcess(this);
	
	connect(process_clean, SIGNAL(finished ( int, QProcess::ExitStatus)),
			this, SLOT(showNotMakeMessages( int, QProcess::ExitStatus)));
	connect(process_make, SIGNAL(finished ( int, QProcess::ExitStatus)),
			this, SLOT(showMakeMessages( int, QProcess::ExitStatus)));
	//	connect(process_make, SIGNAL(finished ( int, QProcess::ExitStatus)),
	//			this, SLOT(showNotMakeMessages( int, QProcess::ExitStatus)));
	connect(process_mount, SIGNAL(finished ( int, QProcess::ExitStatus)),
			this, SLOT(showNotMakeMessages( int, QProcess::ExitStatus)));
	connect(process_umount, SIGNAL(finished ( int, QProcess::ExitStatus)),
			this, SLOT(showNotMakeMessages( int, QProcess::ExitStatus)));
	
	process_clean->setWorkingDirectory(oslabPath + "/Linux-0.11");
	process_make->setWorkingDirectory(oslabPath + "/Linux-0.11");
	process_make->setReadChannelMode(QProcess::MergedChannels);//混合stdout and stderr
	
#ifdef Q_WS_WIN
//	QStringList env = QProcess::systemEnvironment();
//	env.replaceInStrings(QRegExp("^PATH=(.*)", Qt::CaseInsensitive), "PATH=\\1;"
//	"D:\\Program Files\\CodeBlocks\\MinGW\\bin");
//	process_make->setEnvironment(env);
#endif

#ifdef Q_WS_X11
			//process_mount->setWorkingDirectory(oslabPath + "\\filedisk");
			process_umount->setWorkingDirectory(oslabPath + "\\filedisk");
	QMessageBox::information(this, " ", "linux");
#endif
}

BottomOutputWidget::~BottomOutputWidget()
{
	delete m_ui;
}

void BottomOutputWidget::showAllInIt(vector<chain> paths, bool classOrStruct, bool simple)
{
	//leftListIindex = index;//处理定位到定义的需求***********
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(2);
	bool toDef;
	
	if(m_ui->checkBoxDef->isChecked())
		toDef = true;
	else
		toDef = false;
	
	isClassOrStruct = classOrStruct;
	isSimple = simple;
	
	QRegExp classRe("^[\\s]*(typedef)?(extern)?(static)?(const)?(volatile)?"
					"[\\s]*class[\\s]*[0-9A-Za-z_]*[\\s|*]*([{](.*)?)?$");
	QRegExp structRe("^[\\s]*(typedef)?(extern)?(static)?(const)?(volatile)?"
					 "[\\s]*struct[\\s]*[0-9A-Za-z_]*[\\s|*]*([{](.*)?)?$");
	QRegExp symbolRe("^[\\s]*(extern)?(static)?(const)?(volatile)?(unsigned)?"
					 "[\\s]*((struct)|(int)|(char)|(long)|(short)|(float)|(double)|(bool)).*");
	//***************************************************
	
	QString txt;
	txt = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN" "http://www.w3.org/TR/REC-html40/strict.dtd\">"
		  "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">"
		  "p, li { white-space: pre-wrap; }"
		  "</style></head><body style=\" font-family:'Courier'; font-size:9pt; font-weight:400; font-style:normal;\">";
	
	pathsInIdentifier = paths;
	m_ui->progressBar->setMaximum(pathsInIdentifier.size());
	QApplication::setOverrideCursor(Qt::WaitCursor);
	int pos = 1;
	for(unsigned int j = 0; j < pathsInIdentifier.size(); j++)
	{
		m_ui->progressBar->setValue(j + 1);
		QFile file(getPath(j));
		if(!file.open(QIODevice::ReadOnly)) {
			QMessageBox::information(this, "错误无法打开文件", getPath(j));
			continue;
		}
		
		QTextStream in(&file);
		for(int i = 1; i < getRow(j); i++)  //读掉前面无用行
			in.readLine();
		
		QString thisLine = in.readLine().replace("\t", "    ");
		if(toDef)  { //处理定位到定义，只看第一行
			if(isClassOrStruct) {//是类或者结构
				if(classRe.exactMatch(thisLine));
				else if(structRe.exactMatch(thisLine));
				else continue;
			}
			else if(isSimple) {//是简单标示符
				if(symbolRe.exactMatch(thisLine));
				else continue;
			}
		}
		
		txt += "<ul><li>" + QString::number(pos++) + "</li></ul>";
		//********超链接
		txt += "<p><a href=\"";
		txt += QString::number(getRow(j)) + "|";
		txt += getPath(j);
		txt += "\">";
		txt += "Line:" + QString::number(getRow(j)) + "  ";
		txt += getPath(j);
		txt += "</a></p>";
		//**************************
		txt += "<p style=\" margin:0px;\">";
		txt += thisLine;
		txt += "</p>";
		for(int i = 1; i < LINE_TO_VIEW; i++)  //读有用行
		{
			txt += "<p style=\" margin:0px;\">";
			txt += in.readLine().replace("\t", "    ");
			txt += "</p>";
			if(in.atEnd())
				break;
		}
		txt += "<p style=\" margin:0px;\">......</p>";
	}
	txt += "</body></html>";
	m_ui->label->setText(txt);
	txt = "";
	QApplication::restoreOverrideCursor();
}

void BottomOutputWidget::defOrNotText()
{
	showAllInIt(pathsInIdentifier, isClassOrStruct, isSimple);
}

QString BottomOutputWidget::getPath(int i)
{
	return pathInFile[pathsInIdentifier.at(i).path_id];
}

int BottomOutputWidget::getRow(int i)
{
	return pathsInIdentifier.at(i).row;
}

void BottomOutputWidget::clearLabel()
{
	m_ui->label->clear();
}

void BottomOutputWidget::clean()
{
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(1);
	//#ifdef Q_WS_WIN
	process_clean->start("make clean");
	//#endif
	excuted = Make_Clean;
}

void BottomOutputWidget::make()
{
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(0);
	for(int i = m_ui->tableWidget->rowCount(); i > 0 ; i--)
		m_ui->tableWidget->removeRow(i - 1);
	//#ifdef Q_WS_WIN
	process_make->start("make -s -w");
	excuted = Make;
	//#endif
	emit statusBarMessage("正在编译...", 0);
}

void BottomOutputWidget::run()
{
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(1);
#ifdef Q_WS_WIN
	QProcess::startDetached(oslabPath + "/run.bat", QStringList(), oslabPath);
#endif
#ifdef Q_WS_X11
	QProcess::startDetached(oslabPath + "/run", QStringList(), oslabPath);
#endif
}

void BottomOutputWidget::mount()
{
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(1);
	//process_mount.start("");
#ifdef Q_WS_WIN
	QProcess::startDetached(oslabPath + "/mount.bat", QStringList(), oslabPath);
#endif
#ifdef Q_WS_X11
	QProcess::startDetached(oslabPath + "/mount-hdc", QStringList(), oslabPath);
#endif
	excuted = Mount;
}

void BottomOutputWidget::umount()
{
	this->parentWidget()->show();
	m_ui->tabWidget->setCurrentIndex(1);
#ifdef Q_WS_WIN
	QProcess::startDetached(oslabPath + "/umount.bat", QStringList(), oslabPath);
#endif
#ifdef Q_WS_X11
	QProcess::startDetached(oslabPath + "umount hdc", QStringList(), oslabPath);
#endif
	excuted = Umount;
}

void BottomOutputWidget::showMakeMessages( int exitCode, QProcess::ExitStatus exitStatus)
{	
	QStringList errorAndWarning =
			QString(process_make->readAllStandardOutput().data()).split("\n");
	QString returnValue;
	QString type;
	QString buildingDir;
	int errorCount = 0;
	int warningCount = 0;
	foreach(QString line, errorAndWarning) {
		returnValue = buildMsgType(line, type);
		if(type == "dir") {
			buildingDir = QDir(returnValue).absolutePath();
		}
		else if(type == "error") {
			errorCount++;
			addTabelWidgetRow();
			int row = m_ui->tableWidget->rowCount() - 1;
			QStringList error = line.split(":");
			m_ui->tableWidget->item(row, 0)->setText(buildingDir + "/" + error.at(0));
			m_ui->tableWidget->item(row, 1)->setText(error.at(1));
			m_ui->tableWidget->item(row, 2)->setText("error:" + error.at(2));
			m_ui->tableWidget->item(row, 0)->setForeground(QBrush(Qt::red));
			m_ui->tableWidget->item(row, 1)->setForeground(QBrush(Qt::red));
			m_ui->tableWidget->item(row, 2)->setForeground(QBrush(Qt::red));
		}
		else if(type == "warning") {
			warningCount++;
			addTabelWidgetRow();
			int row = m_ui->tableWidget->rowCount() - 1;
			QStringList error = line.split(":");
			m_ui->tableWidget->item(row, 0)->setText(buildingDir + "/" + error.at(0));
			m_ui->tableWidget->item(row, 1)->setText(error.at(1));
			m_ui->tableWidget->item(row, 2)->setText("warning:" + error.at(3));
			m_ui->tableWidget->item(row, 0)->setForeground(QBrush(Qt::blue));
			m_ui->tableWidget->item(row, 1)->setForeground(QBrush(Qt::blue));
			m_ui->tableWidget->item(row, 2)->setForeground(QBrush(Qt::blue));
		}
		else if(type == "func") {
			addTabelWidgetRow();
			int row = m_ui->tableWidget->rowCount() - 1;
			QStringList error = line.split(":");
			m_ui->tableWidget->item(row, 0)->setText(buildingDir + "/" + error.at(0));
			m_ui->tableWidget->item(row, 2)->setText(error.at(1));
		}
		else if(type == "other") {
		}
		m_ui->plainTextEdit->appendPlainText(line.simplified());//去掉回车
		m_ui->plainTextEdit->centerCursor();
	}
	addTabelWidgetRow();
	int row = m_ui->tableWidget->rowCount() - 1;
	m_ui->tableWidget->item(row, 2)->setText("=== Build finished: " +
											 QString::number(errorCount) + " errors, " +
											 QString::number(warningCount) + " warnings ===");
	m_ui->tableWidget->verticalScrollBar()->setSliderPosition(
			m_ui->tableWidget->verticalScrollBar()->maximum());
	showNotMakeMessages(0, QProcess::NormalExit);//只是打印>>>`*'
	//QMessageBox::information(this, "gao", process_make->readAllStandardError().data());
	emit statusBarMessage("编译结束", 5000);
}

void BottomOutputWidget::showNotMakeMessages(int exitCode, QProcess::ExitStatus exitStatus)
{
	QString output;
	
	switch (excuted) {
	case Make_Clean:
		output = process_clean->readAllStandardOutput().data();
		break;
	case Make:
		//output = process_make->readAllStandardOutput().data();
		break;
	case Mount:
		output = process_mount->readAllStandardOutput().data();
		break;
	case Umount:
		output = process_umount->readAllStandardOutput().data();
		break;
	default:
		break;
	}
	output += "命令执行结束\n>>> ";
	m_ui->plainTextEdit->appendPlainText(output);
	m_ui->plainTextEdit->centerCursor();
}


void BottomOutputWidget::changeEvent(QEvent *e)
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void BottomOutputWidget::removingCurrentProject()
{
	m_ui->label->clear();
}

void BottomOutputWidget::addTabelWidgetRow()
{
	int currentRow = m_ui->tableWidget->rowCount();
	m_ui->tableWidget->insertRow(currentRow);
	//QMessageBox::information(0, "错误", QString::number(ui->tableWidget->rowCount()));
	
	QTableWidgetItem *item0 = new QTableWidgetItem;
	item0->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_ui->tableWidget->setItem(currentRow, 0, item0);
	
	QTableWidgetItem *item1 = new QTableWidgetItem;
	item1->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_ui->tableWidget->setItem(currentRow, 1, item1);
	
	QTableWidgetItem *item2 = new QTableWidgetItem;
	item2->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	m_ui->tableWidget->setItem(currentRow, 2, item2);
}

QString BottomOutputWidget::buildMsgType(QString source, QString &type)
{
	QRegExp enteringDirectory("(Entering\\sdirectory)(.*)");

	if(enteringDirectory.indexIn(source, 0) != -1) {
		type = "dir";
		return enteringDirectory.cap(2).mid(2, enteringDirectory.cap(2).length() - 4);
	}
	else if(!source.startsWith("make") && source.split(":").count() == 4) {
		type = "warning";
		return "";
	}
	else if(!source.startsWith("make") && source.split(":").count() == 3
			&& source.at(source.length() - 2) != ':') {//-2因为有回车
		type = "error";
		return "";
	}
	else if(!source.startsWith("make") && source.split(":").count() == 3) {
		type = "func";
		return "";
	}
	else {
		type = "other";
		return "";
	}
}

void BottomOutputWidget::on_tableWidget_activated(QModelIndex index)
{
	if(!m_ui->tableWidget->item(index.row(), 1)->text().isEmpty())
		emit errorFileClicked(m_ui->tableWidget->item(index.row(), 0)->text()
							  , m_ui->tableWidget->item(index.row(), 1)->text().toInt());
}
