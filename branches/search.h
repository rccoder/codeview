#ifndef SEARCH_H
#define SEARCH_H


using namespace std;

#include "struct.h"

class Searcher {
public:
	Searcher();

	void search(string key, int flag,vector <item> &ret);
	void setProject(QString);

private:
	int readin(int flag);
	QString currentProject;

	vector <item> index[3];
};

#endif // SEARCH_H
