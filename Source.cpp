#include "Poem.h"
#include <regex>
#include <string>
#include <iostream>
using namespace std;

string getLine();
string getCommand(int currline);
string command, error;

/// <summary>
/// This program is for editing text files. It uses a Linked List data structure.
/// Ray Winkelman 2015
///
/// SOME THINGS TO NOTE:
///
/// A range can be line 22 to 22. That is simply a range of 1. 
/// The poem class will operate primarily with ranges. The 
/// listRange() or deleteRange() methods both accommodate 1 or 2
/// arguments with a same loop.
///
/// The requirements of the rubric in it's current state doesn't support 
/// adding lines to the end of the file.
///
/// </summary>
/// <param name="argc">The argc.</param>
/// <param name="argv">The argv.</param>
/// <returns></returns>
int main(int argc, char* argv[])
{	
	Poem poem(argv);
	cout << poem.fullList();

	while(true){
		
		command = getCommand(poem.getCurrLine());

		if(regex_match(command, regex("^[A-Z]([ ][0-9]+)?([ ][0-9]+)?"))){
			poem.parseCommand(command);
			error = "";

			if (starts_with(command, "I")){
				poem.addLine(getLine());
				cout << poem.fullList();

			} else if(starts_with(command, "D")){
				poem.deleteRange();
				cout << poem.fullList();

			} else if(starts_with(command, "V")){
				cout << poem.fullList();

			} else if(starts_with(command, "G")){	
				poem.setCurrLine();
				cout << poem.fullList();

			} else if(starts_with(command, "L")){
				cout << poem.listRange();

			} else if(starts_with(command, "S")){
				poem.substitute(getLine());
				cout << poem.fullList();

			} else if(starts_with(command, "E")){
				poem.save();
				poem.exit();
				return 0;

			} else if(starts_with(command, "Q")){
				poem.exit();
				return 0;
			}
		} else {
			error = "That's not a command. ";
			cout << poem.fullList();
		}
	}
}

string getLine(){
	string newline;

	cout << endl << "Enter the line to be inserted." << endl << endl;
	getline(cin, newline);

	system("cls");

	return newline;
}

string getCommand(int currline){
	string cmd;

	cout << endl << error << "Current line is: " << currline << "." << endl;
	getline(cin, cmd);
	trim(cmd);
	to_upper(cmd);

	system("cls");

	return cmd;
}