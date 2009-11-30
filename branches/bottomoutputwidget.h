#ifndef BOTTOMOUTPUTWIDGET_H
#define BOTTOMOUTPUTWIDGET_H

#include <QtGui/QWidget>

#include <QtCore/QProcess>
#include <QtCore/QModelIndex>

#include "struct.h"

using namespace std;

namespace Ui {
    class BottomOutputWidget;
}

class BottomOutputWidget : public QWidget {
    Q_OBJECT
public:
    BottomOutputWidget(QWidget *parent = 0);
    ~BottomOutputWidget();

signals:
	void labelLinkClicked( const QString &);
	void errorFileClicked(QString, int);
	void statusBarMessage(const QString &, int);

public slots:
	void showAllInIt(vector<chain>, bool classOrStruct, bool simple);
	void clearLabel();

	void clean();
	void make();
	void run();
	void mount();
	void umount();
	void removingCurrentProject();


protected:
    void changeEvent(QEvent *e);

private slots:
	void on_tableWidget_activated(QModelIndex index);
 void defOrNotText();
	void showMakeMessages( int exitCode, QProcess::ExitStatus exitStatus);
	void showNotMakeMessages(int exitCode, QProcess::ExitStatus exitStatus);

private:
	void addTabelWidgetRow();
	QString buildMsgType(QString source, QString &type);
	QString getPath(int i);
	int getRow(int i);

    Ui::BottomOutputWidget *m_ui;

	vector<chain> pathsInIdentifier;
	bool isClassOrStruct;
	bool isSimple;

	QProcess * process_clean;
	QProcess * process_make;
	//QProcess process_run;
	QProcess *process_mount;
	QProcess *process_umount;

	enum Excuted {
		Make_Clean,
		Make,
		Mount,
		Umount
	}excuted;
};

#endif // BOTTOMOUTPUTWIDGET_H
