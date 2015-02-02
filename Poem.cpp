#include "Poem.h"

/// <summary>
/// Initializes a new instance of the <see cref="Poem"/> class.
/// </summary>
/// <param name="paths">The paths.</param>
Poem::Poem(char* paths[]) : heaplist(new LinkedList())
{
	this->inpath = paths[1];
	this->outpath = paths[2];

	this->file.open(inpath);
	this->file.makeList(heaplist);

	this->currline = heaplist->GetNumLines();
	this->startrange = 0;
	this->stoprange = 0;
}

/// <summary>
/// Adds a line.
/// </summary>
/// <param name="newline">The newline.</param>
void Poem::addLine(string newline){
	heaplist->InsertAtIndex(currline, newline);
}

/// <summary>
/// Substitutes the specified line.
/// </summary>
/// <param name="newline">The newline.</param>
void Poem::substitute(string newline){
	heaplist->DeleteNode(currline);
	heaplist->InsertAtIndex(currline, newline);
}

/// <summary>
/// Deletes a range.
/// </summary>
void Poem::deleteRange(){
	for (int x = startrange; x <= stoprange; x++){
		heaplist->DeleteNode(startrange);
	}
}

/// <summary>
/// Lists a range.
/// </summary>
/// <returns></returns>
string Poem::listRange(){
	ostringstream templist;

	for (int x = startrange; x <= stoprange; x++){
		templist << x << ":" << spacesForLists(x) << heaplist->GetValue(x) << "\n";
	}
	templist << "\n";

	return templist.str();
}

/// <summary>
/// Sets the current line.
/// </summary>
void Poem::setCurrLine(){
	if(stoprange > this->heaplist->GetNumLines()){
		currline = this->heaplist->GetNumLines() + 1;
	} else {
		currline = stoprange;
	}
}

/// <summary>
/// Gets the current line.
/// </summary>
/// <returns></returns>
int Poem::getCurrLine(){
	return this->currline;
}

/// <summary>
/// Fills the list.
/// </summary>
/// <returns></returns>
string Poem::fullList(){
	ostringstream templist;

	for (int x = 0; x <= heaplist->GetNumLines(); x++){
		templist << x << ":" << spacesForLists(x) << heaplist->GetValue(x) << "\n";
	}
	templist << "\n";

	return templist.str();
}

/// <summary>
/// Returns spaces for lists.
/// </summary>
/// <param name="linenum">The linenum.</param>
/// <returns></returns>
string Poem::spacesForLists(int linenum){
	string spaces;
	if(linenum < 10){
		spaces = "   ";
	} else if(linenum < 100){
		spaces = "  ";
	} else if(linenum < 1000){
		spaces = " ";
	}
	return spaces;
}

/// <summary>
/// Parses the command.
/// </summary>
/// <param name="command">The command.</param>
void Poem::parseCommand(string command){
	ArgList temp;
	int numargs = (args = split(temp, command, is_any_of(" "))).size();
	int numlines = this->heaplist->GetNumLines();

	// If there is one argument, the stop and start are the same.
	// If the argument is a value greater than the total lines, the last line is selected.
	if(numargs > 1){
		this->startrange = (this->stoprange = (convertToInt(args.at(1)) > numlines ? numlines : convertToInt(args.at(1))));
	}
	// If there is two args, start and stop are set accordingly.
	if(numargs > 2){		
		this->startrange = (convertToInt(args.at(1)) > numlines ? numlines : convertToInt(args.at(1)));
		this->stoprange = (convertToInt(args.at(2)) > numlines ? numlines : convertToInt(args.at(2)));
	}
	setCurrLine();
}

/// <summary>
/// Saves this instance.
/// </summary>
void Poem::save(){
	file.save(outpath, heaplist);
}

/// <summary>
/// Exits this instance.
/// </summary>
void Poem::exit(){
	heaplist->~LinkedList();
}

/// <summary>
/// Converts strings to int.
/// </summary>
/// <param name="input">The input.</param>
/// <returns></returns>
int Poem::convertToInt(string input){
	int i;
	try {    
		i = boost::lexical_cast<int>(input);
	} catch (boost::bad_lexical_cast) {
	}
	return i;
}

/// <summary>
/// Splits the string.
/// </summary>
/// <param name="input">The input.</param>
/// <returns></returns>
ArgList Poem::splitString(string input){
	ArgList temp;
	return split(temp, input, is_any_of(" "));
}