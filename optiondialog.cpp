#include <QtGui/QFileDialog>
#include <QtCore/QSettings>

#include "optiondialog.h"
#include "ui_optiondialog.h"

//extern QString oslabPath;//mainwindow.cpp

OptionDialog::OptionDialog(QWidget *parent) :
		QDialog(parent),
		m_ui(new Ui::OptionDialog)
{
	m_ui->setupUi(this);

	connect(m_ui->pushButton, SIGNAL(clicked()), this, SLOT(browseOslabPath()));
	connect(m_ui->pushButton_2, SIGNAL(clicked()), this, SLOT(writeSettings()));
	readSettings();
}

OptionDialog::~OptionDialog()
{
	delete m_ui;
}

void OptionDialog::browseOslabPath()
{
	QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
													"/home",
													QFileDialog::ShowDirsOnly
													| QFileDialog::DontResolveSymlinks);
	if(!dir.isEmpty()) {
		m_ui->lineEdit->setText(dir);
	}
}

void OptionDialog::readSettings()
{
	QSettings settings("ghd_gw", "CodeView");

	settings.beginGroup("MainWindow");
	//oslabPath = settings.value("oslabPath").toString();
	//m_ui->lineEdit->setText(oslabPath);
	settings.endGroup();
}

void OptionDialog::writeSettings()
{
	QSettings settings("ghd_gw", "CodeView");

	settings.beginGroup("MainWindow");
	//oslabPath = m_ui->lineEdit->text();
	//settings.setValue("oslabPath", oslabPath);
	settings.endGroup();

	close();
}

void OptionDialog::changeEvent(QEvent *e)
{
	QDialog::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		m_ui->retranslateUi(this);
		break;
	default:
		break;
	}
}
