#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
	Node *first;
	int totalines;
public:
	LinkedList();
	~LinkedList();
	void Add(string line);
	void DeleteNode(int nodenum);
	string GetValue(int nodenum);
	void InsertAtIndex(int index, string nLine);
	friend ostream& operator<<(ostream& output, LinkedList& list);
	int GetNumLines();
};