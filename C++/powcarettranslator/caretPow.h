#include <iostream>
#include <strings.h>
#include <regex>

#define NOT_FOUND string::npos ///the find method returns this if not found

using namespace std;
int caretPow(string, int []);		//takes a string and array to fill with offsets of symbols and parenthesized expressions
string stringGenerator(string, int []); //takes a string and the previous array of offsets now filled and returns a modified string
