#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QtGui/QDialog>
#include <QtGui/QDirModel>
#include <QtGui/QStringListModel>
#include <QtGui/QProgressDialog>

#include <vector>
#include <string>

#include "indexer.h"

namespace Ui
{
	class PathDialogClass;
}

class PathDialog : public QDialog
{
	Q_OBJECT

public:
	PathDialog(QString curPro, QWidget *parent = 0);
	~PathDialog();
	void setProject(QString, QString);
	void init();

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void traverse();
	void addRootPath();

private:
	Ui::PathDialogClass *ui;
	QString rootPath;
	QStringList filters;
	QString projectName;
	QString projectDcpt;
	std::vector<std::string> allPath;

	void getPath(const QString &path);
	void writePath();

	QProgressDialog *progress;
	QString currentProject;
};

#endif // PATHDIALOG_H
