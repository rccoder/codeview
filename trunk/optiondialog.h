#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QtGui/QDialog>

namespace Ui {
    class OptionDialog;
}

class OptionDialog : public QDialog {
    Q_OBJECT
public:
    OptionDialog(QWidget *parent = 0);
    ~OptionDialog();

protected:
    void changeEvent(QEvent *e);

private slots:
	void browseOslabPath();
	void writeSettings();

private:
	void readSettings();
    Ui::OptionDialog *m_ui;
};

#endif // OPTIONDIALOG_H
