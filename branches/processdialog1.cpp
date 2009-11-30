#include "processdialog1.h"
#include "ui_processdialog1.h"

ProcessDialog1::ProcessDialog1(QWidget *parent) :
    QDialog(parent),
	m_ui(new Ui::ProcessDialog)
{
    m_ui->setupUi(this);
}

ProcessDialog1::~ProcessDialog1()
{
    delete m_ui;
}

void ProcessDialog1::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
