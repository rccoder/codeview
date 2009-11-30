#include <QtGui/QMessageBox>

#include <QtCore/QTextStream>
#include <QtCore/QDir>

#include "delproject.h"
#include "ui_delproject.h"

DelProject::DelProject(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::DelProject)
{
	m_ui->setupUi(this);

	connect(m_ui->listView, SIGNAL(clicked(QModelIndex)),
			this, SLOT(showDcpt(QModelIndex)));
	connect(m_ui->listView, SIGNAL(doubleClicked(QModelIndex)),
			this, SLOT(setCurrentProject()));
	connect(m_ui->delButton, SIGNAL(clicked()),
			this, SLOT(delPro()));
	connect(m_ui->currentButton, SIGNAL(clicked()),
			this, SLOT(setCurrentProject()));
}

void DelProject::init()
{
	allProject.clear();
	QDir dir(QDir::currentPath() + QDir::separator() + "project");

	foreach (QString subDir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
		allProject += subDir;

	pathModel = new QStringListModel(allProject);
	m_ui->listView->setModel(pathModel);
	m_ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置项目不可编辑
}
DelProject::~DelProject()
{
	delete m_ui;
}

void DelProject::changeEvent(QEvent *e)
{
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void DelProject::showDcpt(QModelIndex index)
{
	QString projectName = pathModel->stringList().at(index.row());

	QFile file(QString("project") + QDir::separator() + projectName + QDir::separator() + "dcpt.txt");
	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::information(this, "错误", "读取工程描述错误");
		return;
	}

	QTextStream in(&file);
	QString text = in.readAll();
	m_ui->lineEdit->setText(text);
}

void DelProject::delPro()
{
	if (pathModel->stringList().count() > 0) {
		int r = QMessageBox::warning(this, "删除工程",
									 "是否删除此工程？",
									 QMessageBox::Yes | QMessageBox::No);
		if (r == QMessageBox::Yes) {
			sureDelPro();
			return;
		}
	}
	else
		QMessageBox::information(this, "提示", "无工程可以删除");
}

void DelProject::sureDelPro()
{

	QModelIndex index = m_ui->listView->currentIndex();
	QString projectName = pathModel->stringList().at(index.row());
	QStringList fileToDel;

	if(projectName == "linux-0.11") {
		QMessageBox::warning(this, "提示",
									 "无法删除此工程\n"
									 "如果确实要删除，请到程序程序目录下"
									 "oslab/codeview/project目录下删除linux-0.11文件夹");
		return;
	}

	if (!index.isValid())
		return;

	fileToDel += QString("project") + QDir::separator() + projectName + QDir::separator() + "func.txt";
	fileToDel += QString("project") + QDir::separator() + projectName + QDir::separator() + "simple.txt";
	fileToDel += QString("project") + QDir::separator() + projectName + QDir::separator() + "struct.txt";
	fileToDel += QString("project") + QDir::separator() + projectName + QDir::separator() + "dcpt.txt";
	fileToDel += QString("project") + QDir::separator() + projectName + QDir::separator() + "path.txt";

	QDir dir;

	for(int i = 0; i < fileToDel.count(); i++) {
		if(dir.exists(fileToDel.at(i)))
			if(!dir.remove(fileToDel.at(i))) {
			QMessageBox::information(this, "错误", "删除工程文件失败");
			return;
		}
	}
	if(!dir.rmdir(QString("project") + QDir::separator() + projectName)) {
		QMessageBox::information(this, "错误", "删除工程目录失败");
		return;
	}

	allProject.removeAt(index.row());
	pathModel->setStringList(allProject);
	m_ui->listView->setModel(pathModel);

	m_ui->lineEdit->clear();
	emit projectRemoved(projectName);
}

void DelProject::setCurrentProject()
{
	if (pathModel->stringList().count() > 0) {
		QModelIndex index = m_ui->listView->currentIndex();
		QString projectName = pathModel->stringList().at(index.row());

		//QMessageBox::information(this, "设置成功", "当前工程：" + projectName);

		emit currentProjectChanged(projectName);
	}
	else
		QMessageBox::information(this, "提示", "无工程可以选择");
}
