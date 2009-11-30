#ifndef LEFTINDEXWIDGET_H
#define LEFTINDEXWIDGET_H

#include <QtGui/QWidget>
#include <QtGui/QStringListModel>

#include <QtCore/QModelIndex>
#include <QtCore/QMap>

#include "struct.h"
#include "search.h"

class QTreeWidgetItem;

using namespace std;

namespace Ui {
	class LeftIndexWidget;
}

class LeftIndexWidget : public QWidget {
	Q_OBJECT
public:
	LeftIndexWidget(QWidget *parent = 0);
	~LeftIndexWidget();

protected:
	void changeEvent(QEvent *e);

signals:
	void pathsInIdentifierChanged(vector<chain>, bool classOrStruct, bool simple);
	void tellMainCurrentProjectChanged(QString);
	void tellBottomCurrentProjectChanged();
	void showFileInEditor(QString filename, int line);
	void removingCurrentProject();

public slots:
	void isRemovingCurrentProject(QString);
	void setCurrentProject(QString name);

private slots:
	void on_lineEdit_fileFilter_textEdited(QString );
	void search();
	void enableFindButton(const QString & text);
	void tellBottomPathsInIdentifierChanged(const QModelIndex &);
	void getActivatedFile(QTreeWidgetItem * item, int column);

private:
	void makeList();
	void showProjectFiles(QString rootpath, QTreeWidgetItem *parent);
	void setAllItemsInTreewidgetHidden(QTreeWidgetItem *parent, bool hide);

private:
	Ui::LeftIndexWidget *m_ui;

	QString currentProject;
	bool isRecursive;
	QStringList filters;
	QStringListModel identifierListModel;
	QStringList identifierList;
	QMap<QString, int> map;

	Searcher searcher;
	vector <item> searchResult;   //º£¼ªËÑË÷²¿·Ö
	vector<chain> pathsInIdentifier;
	//
	//	QIcon icon_h;
	//	QIcon icon_c;
	//	QIcon icon_cpp;
	//	QIcon icon_folder;
};

#endif // LEFTINDEXWIDGET_H
