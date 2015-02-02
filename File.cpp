#include "File.h"

File::File(){}
File::~File(){}

void File::open(string path){
	inStream.open(path, std::fstream::in);
}

void File::makeList(LinkedList *list){
	std::string line;

	if (inStream.is_open())
	{
		while (!inStream.eof())
		{
			getline(inStream, line);
			list->Add(line);
		}
		inStream.close();

	} else if(inStream.fail()) {
		//throw error;
	}
}

void File::save(string path, LinkedList *list){
	outStream.open(path, std::fstream::out);

	if (outStream.is_open()) {

		outStream << *list;
		outStream.close();

	} else if(outStream.fail()) {
		//throw error;
	}
}
