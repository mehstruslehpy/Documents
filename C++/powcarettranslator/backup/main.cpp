#include <iostream>
#include <strings.h>
#include <regex>
#include "caretPow.h"
#include <fstream>
#include <limits>
#define NOT_FOUND string::npos ///the find method returns this if not found

using namespace std;

int main()
{
	//declare file objects
	ofstream outFile;
	ifstream inFile;

	//helper variables
	string inputFileName;	//this is the file the user wants to translate
	string userInput;	//this is the string currently being editted at any given time
	int offsets[8];	//this where the offsets for the input string will get returned after the call to caretPow
	cout << "*PLEASE ONLY REFER TO FILES IN THE WORKING DIRECTORY*" << endl;
	cout << "Please enter the name of a file to translate:" << endl;
	cin >> inputFileName;
	//open the input file later we can allow users to choose this
	inFile.open(inputFileName);
	outFile.open("translated.cpp");

	while(getline(inFile, userInput))
	{	
		
		cout << "INPUT LINE: " << userInput << endl;
		if (userInput.find("^") != NOT_FOUND)	//if we find a caret
		{
			while(userInput.find("^") != NOT_FOUND)//keep translating carets til they're gone
			{
				//translate an expression
				//cout << "INPUT LINE: " << userInput << endl;
				caretPow(userInput, offsets);
				userInput = stringGenerator(userInput, offsets);
				//cout << "OUTPUT LINE: " << userInput << endl;
			}
			//write translated expression here
			outFile << userInput << endl;
		}
		else if (userInput.find("//bitwise") != NOT_FOUND)	//if we find our designated escape character skip the following line
		{
			getline(inFile, userInput);
			//inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			outFile << userInput << endl;
		}
		else	//just write the line if neither cases match
		{
			outFile << userInput << endl;
		}
		cout << "OUTPUT LINE: " << userInput << endl;
	}
	cout << "DONE" << endl;

	//clean up as best we can..
	outFile.close();
	inFile.close();
	return 0;
}
