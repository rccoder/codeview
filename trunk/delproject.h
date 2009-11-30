#ifndef DELPROJECT_H
#define DELPROJECT_H

#include <QtGui/QDialog>
#include <QtGui/QStringListModel>

#include <QtCore/QModelIndex>

namespace Ui {
    class DelProject;
}

class DelProject : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(DelProject)
public:
    explicit DelProject(QWidget *parent = 0);
    virtual ~DelProject();
	void init();

protected:
    virtual void changeEvent(QEvent *e);

signals:
	void currentProjectChanged(QString);
	void projectRemoved(QString);

private slots:
	void showDcpt(QModelIndex);
	void delPro();
	void sureDelPro();
	void setCurrentProject();

private:
    Ui::DelProject *m_ui;
	QStringListModel *pathModel;
	QStringList allProject;
};

#endif // DELPROJECT_H
