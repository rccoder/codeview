#ifndef PROCESSDIALOG1_H
#define PROCESSDIALOG1_H

#include <QtGui/QDialog>

namespace Ui {
	class ProcessDialog;
}

class ProcessDialog1 : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(ProcessDialog1)
public:
    explicit ProcessDialog1(QWidget *parent = 0);
    virtual ~ProcessDialog1();
	Ui::ProcessDialog *m_ui;

protected:
    virtual void changeEvent(QEvent *e);
};

#endif // PROCESSDIALOG1_H
