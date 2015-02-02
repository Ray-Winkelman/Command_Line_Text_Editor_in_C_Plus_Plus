#pragma once
#include "LinkedList.h"
#include "File.h"
#include <string>
#include <sstream> 
#include <vector>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

typedef vector<string> ArgList;
using namespace std;
using namespace boost;

class Poem
{
private:
	File file;
	LinkedList *heaplist;
	ArgList args;
	string inpath, outpath;
	int currline, startrange, stoprange;

public:
	Poem(char* argv[]);

	ArgList splitString(string input);

	string listRange();
	string fullList();
	string spacesForLists(int linenum);

	int convertToInt(string input);
	int getCurrLine();

	void parseCommand(string command);
	void substitute(string newline);
	void addLine(string newline);
	
	void deleteRange();	
	void setCurrLine();
	void save();
	void exit();
};

