#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

struct chain
{
	int path_id;
	int row;
};

struct item
{
	std::string identifier;
	std::vector <chain> path;
};

struct temp
{
	std::string idf;
	int file_no;
	int idf_row;
};


#endif // STRUCT_H
