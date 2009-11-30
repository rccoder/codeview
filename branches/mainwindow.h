#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QtGui/QComboBox>
#include <QtGui/QWidget>

#include <QtCore/QModelIndex>
#include <QtCore/QVector>
#include <QtCore/QQueue>

#include "project.h"
#include "search.h"
#include "delproject.h"
#include "struct.h"
#include "linenumberarea.h"

#include "leftindexwidget.h"
#include "bottomoutputwidget.h"
#include "optiondialog.h"

class Highlighter;

namespace Ui
{
	class MainWindowClass;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	void startLabelRecentProClicked(QString);

public slots:
	void newFile();
	void showFileWithLineNumber(const QString & path);

protected:
	void closeEvent(QCloseEvent *event);
	
private slots:
	void startIndexer();

	void findInText(QString);

	void createCodeEditor(QString filename, int line);
	
	void delPro();
	void delProQueue(QString);
	void setCurrentProject(QString);
	
	void open();
	void save();
	void saveAs();
	void cut();
	void copy();
	void paste();
	void about();

	void redo();
	void undo();
	
	void showLeft();
	void showBottom();
	void showOption();

	void closeTab(int);

	void dealStartLable(QString);

	void help();
	void dealFindCombo(int);

	void format();
	
private:
	void dealToolBar();

	QComboBox *combo;
	qint64 checked, checkedNot;
	QIcon checkedIcon, checkedNotIcon;

	Ui::MainWindowClass *ui;
	Project *projectDialog;
	DelProject *delproject;

	QString currentProject;
	
	QString searchString;
	QTextDocument *document;
	
	QString lastString;
	
	void makeList();
	void gotoline(CodeEditer*, int);
	CodeEditer *activeEditor();
	
	QString getPath(int);
	int getRow(int);
	void initLable();
	void addRecentFile(QString s);

	QVector<CodeEditer*> allEditer;
	QVector<Highlighter*> allHighlighter;

	QQueue<QString> recentPro;
	QQueue<QString> recentFile;

	const QModelIndex leftListIindex;

private:
	LeftIndexWidget *leftIndexWidget;
	BottomOutputWidget *bottomOutputWidget;
	OptionDialog optionDialog;
};

#endif // MAINWINDOW_H
