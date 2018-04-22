#include <iostream>
#include <string>
#include <cmath>
#include <sstream> 
#include <vector>
#include <algorithm>

//the max length of translated chars
const int CONV_LEN = 20;
//the max amount of chars to ignore on stdin
const int MAX_IGNORE = 256;
using namespace std;

int readBase();
string readAllocStr();
int getBase10Val(string, int);
void printNewBase(string, int, int);

int main()
{
	unsigned int ibase = 0;
	unsigned int obase = 0;
	unsigned int bval  = 0;
	string instr;

	cout << "For the input base: " << endl;
	ibase = readBase();
	instr = readAllocStr();
	cout << "For the output base: " << endl;
	obase = readBase();
	bval = getBase10Val(instr,ibase);
	cout << endl;
	cout << "xlat-value: ";
	printNewBase(instr,obase,bval);	
	cout << "input-base: " << ibase << endl;
	cout << "output-base: " << obase << endl;
	cout << "base-ten-value: " << bval << endl;
	cout << "input-string: " << instr << endl;	
	return 0;
}

int readBase()
{
	int ret = 0;
	cout << "Enter an unsigned integer base:" << endl;
	cin >> ret;
	return ret;
}
//a dot separated list allows larger bases to work more easily and also makes string 
//handling easier too. Think of a base 360 number 2308, how do we know which group
//of characters corresponds to each place value of 360? it could be 2.308 or 230.8
//using points like this makes life a lot easier in the integers.
string readAllocStr()
{
	string ret;
	cout << "Enter a period separated number in your chosen base: " << endl; 
	cout << "Ex: 1.2.3. is the base 10 number 123" << endl;
	cin.ignore(MAX_IGNORE,'\n');	
	getline(cin,ret);
	return ret;
}
int getBase10Val(string str, int ibase)
{
	int digit = 0;
	stringstream strm(str);
	int j = 0;
	int d_i = 0;
	vector<int> vec;
	reverse(str.begin(),str.end());
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if (str.at(i) == '.')
		{
			i++;
		}
		d_i = int(str[i]) - '0';
		digit += d_i * pow(ibase,j);
		j++;
	}
	return digit;
}

void printNewBase(string str,int obase,int value) 
{
	int digit = 0;
	int y = 0;
	cout << endl;
	for (int i = CONV_LEN; i >= 0 ;--i)
	{
		if ( i != CONV_LEN) cout << '.';
		y = (int)floor( value / pow(obase,i));
		digit = y % obase;
		cout << digit;
	}
	cout << '.' << endl;
}
