#ifndef PROJECT_H
#define PROJECT_H

#include <QtGui/QDialog>
#include "pathDialog.h"

namespace Ui {
    class Project;
}

class Project : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(Project)
public:
    explicit Project(QWidget *parent = 0);
    virtual ~Project();
	void init();

protected:
    virtual void changeEvent(QEvent *e);

private slots:
	void showPathDialog();

private:
    Ui::Project *m_ui;
	PathDialog *pathDialog;
};

#endif // PROJECT_H
