#include <iostream>
#include <strings.h>
#include <regex>
#include <boost/algorithm/string/replace.hpp>

#define NOT_FOUND string::npos ///the find method returns this if not found

using namespace std;

int caretPow(string inLine, int offsets[])
{
	//string inLine;						//input string
	regex singleCaret (".*(\^).*");		//we use this to look for a caret in our input expression
	//int offsets[8] = {-1, -1, -1, -1, -1, -1, -1, -1};	//an array of 8 integers corresponding to the offsets for parens and symbols below
	int count = 0;						//used to tally parens zero means we have finished matching open = +1 close = -1 or open =-1 close = +1
	int pos = 0;						//tracks indexes into our string

					
	int lhoParen = -1;		//left hand side open paren
	int lhcParen = -1;		//left hand side close paren
	int rhoParen = -1;		//right hand side open paren
	int rhcParen = -1;		//right hand side close paren
	
	//in the case of symbol^symbol or some combination
	int lhsSymbols = -1;		//the left hand side symbol
	int lhsSymbole = -1;		//the left hand side symbol
	int rhsSymbols = -1;		//the right hand side symbol
	int rhsSymbole = -1;		//the right hand side symbol

	//getline(cin, inLine);	//get a line this can be eliminated later to process by line input files

	if (regex_match(inLine, singleCaret))
	{
		//cout << "MATCH!" << endl;
		pos = inLine.find("^");
		pos = pos - 1;
		
		//consume lhs white space til we reach a open paren
		while (inLine.at(pos) == ' ' && inLine.at(pos) != ')' && pos != 0)
		{
			pos = pos - 1;
		}		
		//if this is still a white space then the user entered something invalid and we should exit
		if (inLine.at(pos) == ' ')
		{
			cout << "ERROR: INVAID EXPRESSION ON LEFT HAND SIDE OF EXPONENT" << endl;
			return 0;
		}
		//match parentheses on lhs of caret
		do
		{
			if (inLine.at(pos) == ')')
			{
				count = count + 1;
				//cout << "PLUS ONE" << endl;
				pos = pos - 1;
				lhcParen = pos + 1;
			}
			else if (inLine.at(pos) == '(')
			{
				count = count - 1;
				//cout << "MINUS ONE" << endl;
				pos = pos - 1;
				lhoParen = pos + 1;
			}
			else
			{
				//cout << "NEXT ELEMENT" << endl;
				pos = pos - 1;
			}
		} while (count != 0 && pos >= 0);

		//cout << "DONE COUNTING! left hand side of first caret" << endl;
		
		count = 0;
		pos = inLine.find("^");
		pos = pos + 1;
			
		//consume rhs white space til we reach an open paren
		while (inLine.at(pos) == ' ' && inLine.at(pos) != '(' && (inLine.length() - 1) != pos)
		{
			pos = pos + 1;
		}		
		//if this is still a white space then the user entered something invalid and we should exit
		if (inLine.at(pos) == ' ')
		{
			cout << "ERROR: INVAID EXPRESSION ON RIGHT HAND SIDE OF EXPONENT" << endl;
			return 0; //we should probably just skip over this line but returning now might be good
		}
	
		//match parens on right hand side of caret
        do
        {
            if (inLine.at(pos) == '(')
            {
                count = count + 1;
                //cout << "PLUS ONE" << endl;
                pos = pos + 1;
                rhoParen = pos - 1;
            }
            else if (inLine.at(pos) == ')')
            {
                count = count - 1;
                //cout << "MINUS ONE" << endl;
                pos = pos + 1;
                rhcParen = pos - 1;
            }
            else
            {
                //cout << "NEXT ELEMENT" << endl;
                pos = pos + 1;
            }
        } while (count != 0 && pos <= inLine.length());

		//evaluate the symbol on the left hand side if we know it is not a parenthesized expression
		pos = inLine.find("^");
		pos = pos - 1;
		if (lhcParen == -1)
		{
			//kill off any white space..
			while (inLine.at(pos) == ' ')
				pos = pos - 1;

			//set the end of the symbol to position if isalnum is true
			if (isalnum(inLine.at(pos)))
				lhsSymbole = pos;
			
			while (pos != -1 && inLine.at(pos) != ' ' && pos >= 0 && isalnum(inLine.at(pos)))
			{
				//set the start to whatever the new position is
				pos = pos - 1;
				lhsSymbols = pos + 1;
				if (pos <= 0)	//I'm an idiot, this breaks out when we hit the end of the array
				{
					lhsSymbols = pos;
					break;
				}
			}
			//if we get here and:
			//start is neg 1 but end is not
			//we need to consume some whitespace..
			if (lhsSymbols == -1 && lhsSymbole != -1 )
				lhsSymbols = lhsSymbole;
		}
	}

	//evaluate the symbol on the right hand side if we know it is not a parenthesized expression
	pos = inLine.find("^");
	pos = pos + 1;
	if (rhoParen == -1)
	{
		//kill off any white space..
		while (inLine.at(pos) == ' ' && pos != inLine.length())
			pos = pos + 1;
		//set the end of the symbol to position if isalnum is true
		if (isalnum(inLine.at(pos)))
			rhsSymbols = pos;
		
		while (pos != -1 && inLine.at(pos) != ' ' && pos <= inLine.length() && isalnum(inLine.at(pos)))
		{
			//cout << "DEBUG" << endl;
			//set the start to whatever the new position is
			pos = pos + 1;
			rhsSymbole = pos - 1;
			if (pos >= inLine.length())	//I'm an idiot, this breaks out when we hit the end of the array
			{
				rhsSymbole = pos - 1;
				break;
			}
		}
		//if we get here and:
		//start is neg 1 but end is not
		//we need to consume some whitespace..
		if (rhsSymbols == -1 && rhsSymbole != -1 )
		{
			rhsSymbols = rhsSymbole;
		}
	}
	//cout << "lhoParen: " << lhoParen << endl;
	//cout << "lhcParen: " << lhcParen << endl;
	//cout << "rhoParen: " << rhoParen << endl;
	//cout << "rhcParen: " << rhcParen << endl << endl;
	//cout << "lhsSymbols: " << lhsSymbols << endl;
	//cout << "lhsSymbole: " << lhsSymbole << endl;
	//cout << "rhsSymbols: " << rhsSymbols << endl;
	//cout << "rhsSymbole: " << rhsSymbole << endl;

	//setup our return values
	offsets[0] = lhoParen;
	offsets[1] = lhcParen;
	offsets[2] = rhoParen;
	offsets[3] = rhcParen;
	
	offsets[4] = lhsSymbols;
	offsets[5] = lhsSymbole;
	offsets[6] = rhsSymbols;
	offsets[7] = rhsSymbole;

	return 0;
}

string stringGenerator(string strtStr, int offsets[])
{
	//these will be offsets in the original string to be replaced..
	int lhOffsetStrt;			//left hand side offsetStart
	int rhOffsetStop;			//right hand side offsetStop
	string lhSubstr;	//left hand substring
	string rhSubstr;	//right hand substring
	string exprString;	//the full caret expression
	string temp = ""; //hopefully this works..
	temp = strtStr; //hopefully this works..
	exprString = "pow("; //we want it to start with this  

	//grab the left hand side substring
	
	if (offsets[0] != -1 && offsets[1] != -1) //check if it's a parenthesized expression
	{
		lhOffsetStrt = offsets[0];
		//return substring starting at offsets[0] and as long as the difference between the two..
		lhSubstr = strtStr.substr(offsets[0] + 1, (offsets[1] - offsets[0] - 1));
		//cout << "LHS PAREN EXPR!" << endl;
	} 
	else if (offsets[4] != -1 && offsets[5] != -1) //check if it's a symbol
	{
		lhOffsetStrt = offsets[4];
		lhSubstr = strtStr.substr(offsets[4], (offsets[5] - offsets[4] + 1));
		//cout << "LHS SYMBOL EXPR!" << endl;
	}
	else											//if it's neither then something is wrong..
	{
		cout << "IMPROPER LEX/PARSE LHS OF INPUT" << endl;
	}

	//cout << "LEFT HAND SUBSTRING: " << lhSubstr << endl;

	//grab the right hand side substring


	if (offsets[2] != -1 && offsets[3] != -1) //check if it's a parenthesized expression
	{
		rhOffsetStop = offsets[3];
		rhSubstr = strtStr.substr(offsets[2] + 1, (offsets[3] - offsets[2] - 1));
		//cout << "RHS PAREN EXPR!" << endl;
	} 
	else if (offsets[6] != -1 && offsets[7] != -1) //check if it's a symbol
	{
		rhOffsetStop = offsets[7];
		rhSubstr = strtStr.substr(offsets[6], (offsets[7] - offsets[6] + 1));
		//cout << "RHS SYMBOL EXPR!" << endl;
	}
	else											//if it's neither then something is wrong..
	{
		cout << "IMPROPER LEX/PARSE RHS OF INPUT" << endl;
	}
	//cout << "RIGHT HAND SUBSTRING: " << rhSubstr << endl;
	exprString = exprString + "(" + lhSubstr + "),(" + rhSubstr + "))";
	//cout << "BEFORE REPLACE STRING: " << temp << endl;
	//I tried to do this with only std lib but this function was really rough to do
	//using the standard string library
	boost::replace_first(temp, temp.substr(lhOffsetStrt, (rhOffsetStop - lhOffsetStrt + 1)), exprString);	
	//cout << "AFTER REPLACE STRING: " << temp << endl;
	return temp;
}

