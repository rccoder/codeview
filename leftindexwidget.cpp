#include "leftindexwidget.h"
#include "ui_leftindexwidget.h"

#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QtCore/QTextStream>
#include <QtCore/QString>

#include <QtGui/QMessageBox>
#include <QtGui/QPixmap>

vector <QString> pathInFile;//没有经过排序的
//extern QString oslabPath;//mainwindow.cpp

LeftIndexWidget::LeftIndexWidget(QWidget *parent) :
		QWidget(parent),
		m_ui(new Ui::LeftIndexWidget)
{
	m_ui->setupUi(this);

	connect(m_ui->pushButton, SIGNAL(clicked()),
			this, SLOT(search()));
	connect(m_ui->lineEdit, SIGNAL(textEdited(const QString &)),
			this, SLOT(enableFindButton(const QString &)));
	connect(m_ui->listView, SIGNAL(activated(const QModelIndex &)),
			this, SLOT(tellBottomPathsInIdentifierChanged(const QModelIndex &)));
	connect(m_ui->treeWidget, SIGNAL(itemDoubleClicked ( QTreeWidgetItem *, int)),
			this, SLOT(getActivatedFile(QTreeWidgetItem *, int)));
}

LeftIndexWidget::~LeftIndexWidget()
{
	delete m_ui;
}

void LeftIndexWidget::setCurrentProject(QString name)
{
	QDir dir;
	if(!dir.exists("project/"+ name)) {
		QMessageBox::information(this, "提示", "所选工程已被删除");
		return;
	}

	identifierList.clear();
	identifierListModel.setStringList(identifierList);
	m_ui->listView->setModel(&identifierListModel);
	m_ui->lineEdit->clear();
	pathInFile.clear();

	currentProject = name;
	emit tellMainCurrentProjectChanged(currentProject);
	//m_ui->label->clear();
	//QMessageBox::information(this, "设置成功", "当前工程：" + name);
	QFile file("project/" + name + "/path.txt");

	if(!file.open(QIODevice::ReadOnly))
	{
		QMessageBox::information(this, "不能打开文件", file.fileName());
		return;
	}

	QTextStream in(&file);
	QString rootPath = in.readLine();
	filters = in.readLine().split("|");
	if(name == "linux-0.11")
		filters << "*.s" << "*.S";
	QString recursive = in.readLine();
	if(recursive == "recursive")
		isRecursive = true;
	else
		isRecursive = false;
	m_ui->tabWidget_2->setCurrentIndex(0);
	m_ui->treeWidget->clear();
	showProjectFiles(rootPath, m_ui->treeWidget->invisibleRootItem());
	while(!in.atEnd())
		pathInFile.push_back(in.readLine());
}

void LeftIndexWidget::showProjectFiles(QString rootpath, QTreeWidgetItem *parent)
{
	QDir dir(rootpath);
	QIcon icon_h(":/iamge/iamges/h.png");
	QIcon icon_c(":/iamge/iamges/c.png");
	QIcon icon_cpp(":/iamge/iamges/cpp.png");
	QIcon icon_s(":/iamge/iamges/asm.png");
	QIcon icon_folder(":/iamge/iamges/folder.png");

	QTreeWidgetItem *item = 0;

	foreach (QFileInfo fileInfo, dir.entryInfoList(filters,
												   QDir::Files | QDir::AllDirs | QDir::NoDotAndDotDot,
												   QDir::DirsFirst | QDir::Name)) {
		item = new QTreeWidgetItem(parent);
		item->setText(0, fileInfo.fileName());
		item->setFirstColumnSpanned(true);
		if(fileInfo.isFile())
			item->setToolTip(0, fileInfo.absoluteFilePath());

		QString ext = fileInfo.suffix().toLower();

		if(ext == "h")
			item->setIcon(0, icon_h);
		else if(ext == "c")
			item->setIcon(0, icon_c);
		else if(ext == "cpp")
			item->setIcon(0, icon_cpp);
		else if(ext == "s")
			item->setIcon(0, icon_s);
		else
			item->setIcon(0, icon_folder);

		if(fileInfo.isDir()) {
			if(isRecursive) {
				//QMessageBox::information(this, tr("Error"), fileInfo.path());
				showProjectFiles(fileInfo.absoluteFilePath(), item);
			}
		}
	}
}

void LeftIndexWidget::search()
{
	if(currentProject.isEmpty()) {
		QMessageBox::information(this, "提示", "请先选择工程");
		return;
	}

	QDir dir;
	if(!dir.exists("project/" + currentProject)) {
		QMessageBox::information(this, "提示", "所选工程不存在或已被删除");
		return;
	}

	QString wordToSearch = m_ui->lineEdit->text();

	if(wordToSearch.isEmpty())
		QMessageBox::information(this, "提示", "请填写所要查找的关键字");
	else {
		m_ui->pushButton->setEnabled(false);   //防止重新搜索
		searcher.setProject(currentProject);
		if(searchResult.size() > 0)
			searchResult.clear();
		if(m_ui->radioButton->isChecked())
			searcher.search(wordToSearch.toAscii().data(), 2, searchResult);
		else if(m_ui->radioButton_2->isChecked())
			searcher.search(wordToSearch.toAscii().data(), 1, searchResult);
		else if(m_ui->radioButton_3->isChecked())
			searcher.search(wordToSearch.toAscii().data(), 0, searchResult);
		makeList();
	}
}


void LeftIndexWidget::makeList()
{
	if(map.count() > 0)
		map.clear();
	if(identifierList.count() > 0)
		identifierList.clear();

	for(unsigned int i = 0; i < searchResult.size(); i++)
	{
		map.insert(searchResult[i].identifier.c_str(), i);
		identifierList += searchResult[i].identifier.c_str();
	}

	qSort(identifierList.begin(), identifierList.end()); //排序
	identifierListModel.setStringList(identifierList);
	int index = identifierList.indexOf(m_ui->lineEdit->text());
	if(index != -1) {

		QModelIndex indx = identifierListModel.index(index);
		m_ui->listView->scrollTo(QModelIndex(indx), QAbstractItemView::PositionAtTop);
	}

	m_ui->listView->setModel(&identifierListModel);
	m_ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置项目不可编辑
}

void LeftIndexWidget::enableFindButton(const QString & text)
{
	m_ui->pushButton->setEnabled(true);
}

void LeftIndexWidget::tellBottomPathsInIdentifierChanged(const QModelIndex & index)
{
	QString text = identifierList.at(index.row());//得到所点击的文本
	int arrayIndex = map[text];   //通过映射得到此文本在数组中的下标
	pathsInIdentifier = searchResult[arrayIndex].path;

	emit pathsInIdentifierChanged(pathsInIdentifier,
								  m_ui->radioButton_2->isChecked(),
								  m_ui->radioButton_3->isChecked());
}

void LeftIndexWidget::getActivatedFile(QTreeWidgetItem * item, int column)
{
	if(!item->toolTip(0).isEmpty())
		emit showFileInEditor(item->toolTip(0), 1);
}
void LeftIndexWidget::changeEvent(QEvent *e)
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

void LeftIndexWidget::on_lineEdit_fileFilter_textEdited(QString text)
{
	if(!text.isEmpty()) {
		setAllItemsInTreewidgetHidden(m_ui->treeWidget->invisibleRootItem(), true);

		foreach(QTreeWidgetItem * item, m_ui->treeWidget->findItems(text,
																	Qt::MatchRecursive |
																	Qt::MatchStartsWith, 0)) {
			QTreeWidgetItem * temp = item;
			while(temp->parent()) {
				temp->parent()->setHidden(false);
				temp = temp->parent();
			}
			item->setHidden(false);
		}
		m_ui->treeWidget->expandAll();
	}
	else {
		setAllItemsInTreewidgetHidden(m_ui->treeWidget->invisibleRootItem(), false);
		m_ui->treeWidget->collapseAll();
	}
}

void LeftIndexWidget::setAllItemsInTreewidgetHidden(QTreeWidgetItem *parent, bool hide)
{
	if(parent->childCount() > 0) {
		for(int i = 0; i < parent->childCount(); i++) {
			setAllItemsInTreewidgetHidden(parent->child(i), hide);
			parent->child(i)->setHidden(hide);
		}
	}
}

void LeftIndexWidget::isRemovingCurrentProject(QString name)
{
	if(name == currentProject) {
		m_ui->treeWidget->clear();
		m_ui->listView->setModel(&QStringListModel());
		m_ui->lineEdit->clear();
		m_ui->lineEdit_fileFilter->clear();

		emit removingCurrentProject();
	}
}
