#pragma once
#include <string>

using namespace std;

class Node
{
public:
	string line;
	Node *next;

	Node();
	~Node();
};

