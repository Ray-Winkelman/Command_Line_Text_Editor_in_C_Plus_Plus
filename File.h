#pragma once
#include <fstream>
#include <string>
#include "LinkedList.h"

class File
{
private:
	std::ifstream inStream;
	std::ofstream outStream;

public:
	File();
	~File();
	void open(std::string path);
	void makeList(LinkedList *list);
	void save(string path, LinkedList *list);
};

