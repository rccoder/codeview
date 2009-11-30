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
	m_ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers); //������Ŀ���ɱ༭
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
		QMessageBox::information(this, "����", "��ȡ������������");
		return;
	}

	QTextStream in(&file);
	QString text = in.readAll();
	m_ui->lineEdit->setText(text);
}

void DelProject::delPro()
{
	if (pathModel->stringList().count() > 0) {
		int r = QMessageBox::warning(this, "ɾ������",
									 "�Ƿ�ɾ���˹��̣�",
									 QMessageBox::Yes | QMessageBox::No);
		if (r == QMessageBox::Yes) {
			sureDelPro();
			return;
		}
	}
	else
		QMessageBox::information(this, "��ʾ", "�޹��̿���ɾ��");
}

void DelProject::sureDelPro()
{

	QModelIndex index = m_ui->listView->currentIndex();
	QString projectName = pathModel->stringList().at(index.row());
	QStringList fileToDel;

	if(projectName == "linux-0.11") {
		QMessageBox::warning(this, "��ʾ",
									 "�޷�ɾ���˹���\n"
									 "���ȷʵҪɾ�����뵽�������Ŀ¼��"
									 "oslab/codeview/projectĿ¼��ɾ��linux-0.11�ļ���");
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
			QMessageBox::information(this, "����", "ɾ�������ļ�ʧ��");
			return;
		}
	}
	if(!dir.rmdir(QString("project") + QDir::separator() + projectName)) {
		QMessageBox::information(this, "����", "ɾ������Ŀ¼ʧ��");
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

		//QMessageBox::information(this, "���óɹ�", "��ǰ���̣�" + projectName);

		emit currentProjectChanged(projectName);
	}
	else
		QMessageBox::information(this, "��ʾ", "�޹��̿���ѡ��");
}
