#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <QtGui/QDesktopServices>
#include <QtGui/QScrollBar>

#include <QtCore/QTextStream>
#include <QtCore/QUrl>
#include <QtCore/QProcess>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "highlighter.h"
#include "about.h"
#include "stdio.h"

using namespace std;

extern vector <QString> pathInFile;//没有经过排序的

#define RECENT_PRO 3
#define RECENT_FILE 6


MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent), ui(new Ui::MainWindowClass)
{
	ui->setupUi(this);
	initLable();
	dealToolBar();
	setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
	
	//左边的何下边的
	leftIndexWidget = new LeftIndexWidget(ui->dockWidget);
	bottomOutputWidget = new BottomOutputWidget(ui->dockWidget_2);
	connect(leftIndexWidget, SIGNAL(tellBottomCurrentProjectChanged()),
			bottomOutputWidget, SLOT(clearLabel()));
	connect(leftIndexWidget, SIGNAL(pathsInIdentifierChanged(vector<chain>, bool ,bool)),
			bottomOutputWidget, SLOT(showAllInIt(vector<chain>, bool ,bool)));

	connect(leftIndexWidget, SIGNAL(tellMainCurrentProjectChanged(QString)),
			this, SLOT(setCurrentProject(QString)));
	if(QFile::exists("project/linux-0.11"))//信号连上了再调
		leftIndexWidget->setCurrentProject("linux-0.11");

	connect(leftIndexWidget, SIGNAL(showFileInEditor(QString, int)),
			this, SLOT(createCodeEditor(QString, int)));
	connect(this, SIGNAL(startLabelRecentProClicked(QString)),
			leftIndexWidget, SLOT(setCurrentProject(QString)));
	connect(leftIndexWidget, SIGNAL(removingCurrentProject()),
			bottomOutputWidget, SLOT(removingCurrentProject()));

	connect(bottomOutputWidget, SIGNAL(labelLinkClicked(const QString &)),
			this, SLOT(showFileWithLineNumber(const QString &)));
	connect(bottomOutputWidget, SIGNAL(errorFileClicked(QString, int)),
			this, SLOT(createCodeEditor(QString, int)));
	connect(bottomOutputWidget, SIGNAL(statusBarMessage(const QString &, int)),
			this->statusBar(), SLOT(showMessage(const QString &, int)));

	ui->dockWidget->setWidget(leftIndexWidget);
	ui->dockWidget->setMinimumSize (200, 400);
	ui->dockWidget_2->setWidget(bottomOutputWidget);
	ui->dockWidget_2->setVisible(false);

	connect(ui->action_4, SIGNAL(triggered()),
			bottomOutputWidget, SLOT(clean()));
	connect(ui->action_make, SIGNAL(triggered()),
			bottomOutputWidget, SLOT(make()));
	connect(ui->action_run, SIGNAL(triggered()),
			bottomOutputWidget, SLOT(run()));
	connect(ui->actionMount, SIGNAL(triggered()),
			bottomOutputWidget, SLOT(mount()));
	connect(ui->actionUmount, SIGNAL(triggered()),
			bottomOutputWidget, SLOT(umount()));
	//******************************
	projectDialog = 0;
	delproject = 0;
	
	connect(ui->newProject, SIGNAL(triggered()),
			this, SLOT(startIndexer()));
	connect(ui->delProject, SIGNAL(triggered()),
			this, SLOT(delPro()));
	
	connect(ui->action_showLeft, SIGNAL(triggered()),
			this, SLOT(showLeft()));
	connect(ui->action_showBottom, SIGNAL(triggered()),
			this, SLOT(showBottom()));
	
	connect(ui->tabWidget, SIGNAL(tabCloseRequested ( int)),
			this, SLOT(closeTab(int)));
	
	connect(ui->action_help, SIGNAL(triggered()),
			this, SLOT(help()));
	
	connect(ui->action_Option, SIGNAL(triggered()),
			this, SLOT(showOption()));
	
	connect(ui->action, SIGNAL(triggered()),
			this, SLOT(format()));
	
	connect(combo, SIGNAL(currentIndexChanged(int)),
			this, SLOT(dealFindCombo(int)));
	connect(combo, SIGNAL(editTextChanged ( const QString & )),
			this, SLOT(findInText(QString)));
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::about()
{
	About *a = new About(this);
	a->show();
}

void MainWindow::createCodeEditor(QString filename, int line)
{
	if(ui->tabWidget->tabToolTip(0) == "start") {
		ui->tabWidget->removeTab(0);
		ui->tabWidget->setDocumentMode(true);
	}

	for(int j = 0; j < ui->tabWidget->count(); j++) { //如果文件已经打开
		if(filename == ui->tabWidget->tabToolTip(j))
		{
			ui->tabWidget->setCurrentIndex(j);
			gotoline(activeEditor(), line);
			return;
		}
	}

	QFile file(filename);
	if(!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(this, "打开文件错误", filename);
		return;
	}
	
	CodeEditer *editer = new CodeEditer(ui->tabWidget);
	editer->fileName = filename;
	editer->isUntitled = false;
	allEditer.append(editer);

	Highlighter *h = new Highlighter(editer->document());
	allHighlighter.append(h);

	ui->tabWidget->addTab(editer, "");
	ui->tabWidget->setTabToolTip(allEditer.count() - 1, filename);
	ui->tabWidget->setCurrentIndex (ui->tabWidget->count() - 1);
	
	QTextStream in(&file);
	editer->setPlainText(in.readAll());
	ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), QFileInfo(filename).fileName());//闹听
	gotoline(editer, line);  //跳转到指定行，不过现在好像有些不好使，只是光标到了
	addRecentFile(filename);
}

void MainWindow::showFileWithLineNumber(const QString & path)
{
	QStringList sl = path.split("|");
	int row = sl.at(0).toInt();
	
	createCodeEditor(sl.at(1), row);
}

void MainWindow::gotoline(CodeEditer *e, int line)
{
	QTextCursor tc = e->textCursor();
	int position = e->document()->findBlockByNumber( line-1 ).position();
	tc.setPosition(position,QTextCursor::MoveAnchor);
	e->setTextCursor( tc );
	e->centerCursor();
}

void MainWindow::startIndexer()
{
	if(!projectDialog)
		projectDialog = new Project(this);
	projectDialog->init();
	projectDialog->show();
}

void MainWindow::delPro()
{
	if(!delproject) {
		delproject = new DelProject(this);
		connect(delproject, SIGNAL(currentProjectChanged(QString)),
				leftIndexWidget, SLOT(setCurrentProject(QString)));//先告诉左边的，设置工程成功，再又左边的告诉主的
		connect(delproject, SIGNAL(projectRemoved(QString)),
				this, SLOT(delProQueue(QString)));
		connect(delproject, SIGNAL(projectRemoved(QString)),
				leftIndexWidget, SLOT(isRemovingCurrentProject(QString)));
	}
	delproject->init();
	delproject->show();
	
}

void MainWindow::delProQueue(QString s)
{
	recentPro.removeOne(s);
	if(s == currentProject) {
		currentProject = "";
		pathInFile.clear();
		ui->dockWidget->setWindowTitle("未选择工程");
	}
}

void MainWindow::setCurrentProject(QString name)
{
	if(recentPro.indexOf(name) == -1) {
		if(recentPro.count() < RECENT_PRO) {
			recentPro.enqueue(name);
		}
		else {
			recentPro.dequeue();
			recentPro.enqueue(name);
		}
	}

	if(name == "linux-0.11") {
		ui->action_4->setEnabled(true);
		ui->action_make->setEnabled(true);
		ui->action_run->setEnabled(true);
		ui->actionMount->setEnabled(true);
		ui->actionUmount->setEnabled(true);
	}
	else {
		ui->action_4->setEnabled(false);
		ui->action_make->setEnabled(false);
		ui->action_run->setEnabled(false);
		ui->actionMount->setEnabled(false);
		ui->actionUmount->setEnabled(false);
	}

	ui->dockWidget->setWindowTitle("当前工程:" + name);
	ui->dockWidget->setVisible(true);
	currentProject = name;
}

void MainWindow::newFile()
{
	CodeEditer *editer = new CodeEditer(ui->tabWidget);
	editer->isUntitled = true;
	allEditer.append(editer);
	static int documentNumber = 1;
	
	QString curFile = tr("Untitled%1").arg(documentNumber);
	documentNumber++;
	
	ui->tabWidget->addTab(editer, curFile + "*");
	ui->tabWidget->setTabToolTip(allEditer.count(), curFile + "*");
	ui->tabWidget->setCurrentIndex (ui->tabWidget->count() - 1);
	
	Highlighter *h = new Highlighter(editer->document());
	allHighlighter.append(h);
}

void MainWindow::open()
{
	QString fileName = QFileDialog::getOpenFileName(this,
													"打开文件", ".",
													tr("Source files (*.c *.cpp)\n"
													   "Header files (*.h)\n"
													   "All files (*.*)"));
	if (!fileName.isEmpty())
		createCodeEditor(fileName, 1);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	for (int i = ui->tabWidget->count(); i > 0 ; i--) {
		closeTab(i - 1);
	}

	FILE *p, *p1;

	if ((p = fopen("file", "w")) != NULL) {
		for(int i = recentFile.count(); i > 0 ; i--) {
			fprintf(p, "%s\n", recentFile.at(i - 1).toLocal8Bit().data());
		}
	}

	if ((p1 = fopen("pro", "w")) != NULL) {
		for(int i = recentPro.count(); i > 0 ; i--) {
			fprintf(p1, "%s\n", recentPro.at(i - 1).toLocal8Bit().data());
		}
	}

	if(ui->tabWidget->count() > 0)
		event->ignore();
	else
		event->accept();
}

void MainWindow::save()
{
	if (activeEditor()) {
		activeEditor()->save();
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
								  QFileInfo(activeEditor()->fileName).fileName());
		ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), activeEditor()->fileName);
	}
}

void MainWindow::saveAs()
{
	if (activeEditor()) {
		activeEditor()->saveAs();
		ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),
								  QFileInfo(activeEditor()->fileName).fileName());
		ui->tabWidget->setTabToolTip(ui->tabWidget->currentIndex(), activeEditor()->fileName);
	}
}

void MainWindow::cut()
{
	if (activeEditor())
		activeEditor()->cut();
}

void MainWindow::copy()
{
	if (activeEditor())
		activeEditor()->copy();
}

void MainWindow::paste()
{
	if (activeEditor())
		activeEditor()->paste();
}


void MainWindow::redo()
{
	if (activeEditor())
		activeEditor()->redo();
}

void MainWindow::undo()
{
	if (activeEditor())
		activeEditor()->undo();
}

CodeEditer *MainWindow::activeEditor()
{
	int index = ui->tabWidget->currentIndex();
	if(index == -1)
		return 0;
	return allEditer.at(index);
}

void MainWindow::findInText(QString searchString)
{
	int row, time = 0;
	bool modified;
	if(activeEditor()) {
		document = activeEditor()->document();
		modified = activeEditor()->document()->isModified();
	}
	else
	{
		//QMessageBox::information(this, "提示", "请选择所要查找的文件");
		return;
	}

	if (searchString == "") {
		//QMessageBox::information(this, "提示", "查找内容为空");
		QTextCursor highlightCursor(document);

		QTextCharFormat plainFormat(highlightCursor.charFormat());
		QTextCharFormat colorFormat = plainFormat;

		QBrush br;
		br.setStyle(Qt::NoBrush);
		colorFormat.setBackground(br);

		//highlightCursor.beginEditBlock();
		highlightCursor.select(QTextCursor::Document);
		highlightCursor.mergeCharFormat(colorFormat);
		//highlightCursor.endEditBlock();
	}
	else {
		//********************************清除格式
		QTextCursor highlightCursor(document);

		QTextCharFormat plainFormat(highlightCursor.charFormat());
		QTextCharFormat colorFormat = plainFormat;

		QBrush br;
		br.setStyle(Qt::NoBrush);
		colorFormat.setBackground(br);

		//highlightCursor.beginEditBlock();
		highlightCursor.select(QTextCursor::Document);
		highlightCursor.mergeCharFormat(colorFormat);
		//highlightCursor.endEditBlock();
		//***********************************

		row = activeEditor()->textCursor().blockNumber();

		QTextCursor highlightCursor1(document);
		QTextCursor cursor1(document);
		QTextCharFormat plainFormat1(highlightCursor1.charFormat());
		QTextCharFormat colorFormat1 = plainFormat1;
		
		//highlightCursor1.beginEditBlock();
		colorFormat1.setBackground(QColor(255, 255, 0));

		while (!highlightCursor1.isNull() && !highlightCursor1.atEnd()) {
			if(combo->itemIcon(1).cacheKey() == checked &&
			   combo->itemIcon(2).cacheKey() == checkedNot )
				highlightCursor1 = document->find(searchString, highlightCursor1,
												  QTextDocument::FindCaseSensitively);
			else if(combo->itemIcon(1).cacheKey() == checkedNot &&
					combo->itemIcon(2).cacheKey() == checked)
				highlightCursor1 = document->find(searchString, highlightCursor1,
												  QTextDocument::FindWholeWords);
			else if(combo->itemIcon(1).cacheKey() == checked &&
					combo->itemIcon(2).cacheKey() == checked)
				highlightCursor1 = document->find(searchString, highlightCursor1,
												  QTextDocument::FindWholeWords
												  | QTextDocument::FindCaseSensitively);
			else
				highlightCursor1 = document->find(searchString, highlightCursor1);


			if(!highlightCursor1.isNull()) {
				if(time == 0)
					row = highlightCursor1.blockNumber();
				time++;
				highlightCursor1.mergeCharFormat(colorFormat1);
			}
		}
		//highlightCursor1.endEditBlock();
		lastString = searchString;
		gotoline(activeEditor(), row + 1);
	}
	if(!modified)
		activeEditor()->document()->setModified(false);
}

void MainWindow::showLeft()
{
	if(!ui->dockWidget->isVisible())
		ui->dockWidget->show();
}

void MainWindow::showOption()
{
	optionDialog.show();
}

void MainWindow::showBottom()
{
	if(!ui->dockWidget_2->isVisible())
		ui->dockWidget_2->show();
}

void MainWindow::closeTab(int index)
{
	//QMessageBox::information(this, "", ui->tabWidget->tabToolTip(index));
	if(ui->tabWidget->tabToolTip(index) == "start") {
		ui->tabWidget->removeTab(index);
		ui->tabWidget->setDocumentMode(true);
		return;
	}

	if(allEditer.at(index)->document()->isModified()) {
		int r = QMessageBox::warning(this, "文件已经被修改，是否保存",
									 ui->tabWidget->tabToolTip(index),
									 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (r == QMessageBox::Yes)
			allEditer.at(index)->save();
		else if(r == QMessageBox::No)
		{}
		else
			return;
	}

	ui->tabWidget->removeTab(index);
	delete allHighlighter.at(index);
	delete allEditer.at(index);
	allEditer.remove(index);
	allHighlighter.remove(index);
}

void MainWindow::dealStartLable(QString s)
{
	if(s == "1")
		startIndexer();
	else if(s == "2")
		delPro();
	else if(QString(s.at(s.length()-1)) == "3") {
		s.remove(s.length()-1, 1);
		createCodeEditor(s, 1);
	}
	else {
		emit startLabelRecentProClicked(s.remove(s.length()-1, 1));
	}
}

void MainWindow::initLable()
{
	QString rF = "<ul>", rP = "<ul>";

	QFile fileF("file");
	if (!fileF.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox::warning(this, "载入配置文件错误",
							 "无法读取最近工程文件");
	}
	else {
		QTextStream in(&fileF);
		while(!in.atEnd()) {
			QString s;
			in >> s;
			recentFile.enqueue(s);
			rF += "<li><a href=\"" + s + "3\">" + s;
		}
		rF += "</ul>";
		if(recentFile.count() > 0)
			ui->label_recentFile->setText(rF);
	}

	QFile fileP("pro");
	if (!fileP.open(QIODevice::ReadOnly | QIODevice::Text)) {
		QMessageBox::warning(this, "载入配置文件错误",
							 "无法读取最近工程文件");
	}
	else {
		QTextStream in(&fileP);
		while(!in.atEnd()) {
			QString s;
			in >> s;
			recentPro.enqueue(s);
			rP += "<li><a href=\"" + s + "4\">" + s;
		}
		rP += "</ul>";
		if(recentPro.count() > 0)
			ui->label_recentPro->setText(rP);
	}
}

void MainWindow::addRecentFile(QString s)
{
	if(recentFile.indexOf(s) == -1) {
		if(recentFile.count() < RECENT_FILE) {

			recentFile.enqueue(s);
		}
		else {
			recentFile.dequeue();
			recentFile.enqueue(s);
		}
	}
}

void MainWindow::help()
{
	if(!QDesktopServices::openUrl(QUrl("./Help.chm")))
		QMessageBox::warning(this, "错误", "找不到帮助文件");
}

void MainWindow::dealToolBar()
{
	checkedIcon.addFile(":/iamge/iamges/sure.png");
	checkedNotIcon.addFile(":/iamge/iamges/sureNot.png");

	checked = checkedIcon.cacheKey();
	checkedNot = checkedNotIcon.cacheKey();

	combo = new QComboBox(this);

	QLabel *findLabel = new QLabel(" 查找 ", this);
	ui->mainToolBar->addWidget(findLabel);

	combo->addItem("");
	combo->addItem(checkedNotIcon, "区分大小写");
	combo->addItem(checkedIcon, "匹配整个单词");
	combo->setEditable(true);
	combo->setSizeAdjustPolicy(QComboBox::AdjustToContents);
	combo->setMinimumWidth(100);
	ui->mainToolBar->addWidget(combo);
}

void MainWindow::dealFindCombo(int index)
{
	if(index == 0) {
		//combo->setEditable(true);
	}
	else if (index == 1 || index == 2){
		if(combo->itemIcon(index).cacheKey() == checkedNot)
			combo->setItemIcon(index, checkedIcon);
		else
			combo->setItemIcon(index, checkedNotIcon);
	}
	else
		combo->removeItem(index);
	combo->setCurrentIndex(0);
}

void MainWindow::format()
{
	if (activeEditor()) {
		//int line = activeEditor()->textCursor().blockNumber();
		//int line = activeEditor()->firstVisibleBlock().blockNumber();
		int pos = activeEditor()->verticalScrollBar()->sliderPosition();

		activeEditor()->textCursor().beginEditBlock();
		activeEditor()->format();
		activeEditor()->textCursor().endEditBlock();

		activeEditor()->verticalScrollBar()->setSliderPosition(pos);
		activeEditor()->document()->setModified(true);
	}
}
