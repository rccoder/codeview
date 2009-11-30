#include <QtGui>
#include <QtCore>

#include <iostream>
#include <fstream>
#include <string>

#include "search.h"

Searcher::Searcher()
{
}

int Searcher::readin(int flag)
{
	string search_path;
	string projectPath;

	projectPath = currentProject.toLocal8Bit().constData();

	switch (flag)
	{
	case 0:
		search_path = QDir::toNativeSeparators(("project/" + projectPath + "/simple.txt").c_str()).toLocal8Bit().data();
		break;
	case 1:
		search_path = QDir::toNativeSeparators(("project/" + projectPath + "/struct.txt").c_str()).toLocal8Bit().data();
		break;
	case 2:
		search_path = QDir::toNativeSeparators(("project/" + projectPath + "/func.txt").c_str()).toLocal8Bit().data();
		break;
	}

	ifstream F;
	F.open( search_path.c_str() );
	int num;

	if (!F) return 1;

	while (F)
	{
		struct item p;
		F >> p.identifier;
		F >> num;

		for (int i = 0;i < num;i++)
		{
			struct chain q;
			F >> q.path_id;
			F >> q.row;

			p.path.push_back(q);
		}

		index[flag].push_back(p);
	}

	return 0;
}

void Searcher::search(string key, int flag,vector <struct item> &ret)
{
	if (index[flag].size() == 0)
	{
		readin(flag);
	}

	for (int i = 0;i < (int)index[flag].size();i++)
	{
		if (strstr(index[flag][i].identifier.c_str(),key.c_str()) != NULL)
		{
			ret.push_back(index[flag][i]);
		}
	}

	return;
}

void Searcher::setProject(QString s )
{
	currentProject = s;
}
