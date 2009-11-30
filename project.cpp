#include <QtGui/QMessageBox>

#include "project.h"
#include "ui_project.h"

Project::Project(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::Project)
{
	m_ui->setupUi(this);
	pathDialog = 0;
	connect(m_ui->next, SIGNAL(clicked()),
			this, SLOT(showPathDialog()));
}

Project::~Project()
{
	delete m_ui;
}

void Project::init()
{
	m_ui->projectName->clear();
	m_ui->projectDcpt->clear();
}

void Project::changeEvent(QEvent *e)
{
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}

void Project::showPathDialog()
{
	QDir dir;

	if(m_ui->projectName->text().isEmpty())
	{
		QMessageBox::information(this, "提示", "工程名字不能为空");
		return;
	}
	if(dir.exists(QString("project")  + QDir::separator() + m_ui->projectName->text())){
		QMessageBox::information(this, "错误", "工程已经存在");
		return;
	}

	close();

	if(!pathDialog)
		pathDialog = new PathDialog(m_ui->projectName->text(), this);
	pathDialog->setProject(m_ui->projectName->text(), m_ui->projectDcpt->text());
	pathDialog->init();
	pathDialog->show();
}
