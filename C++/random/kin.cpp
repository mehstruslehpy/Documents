#include <iostream>

using namespace std;

int countPos()
{
	int val = 0;
	string input;
	cin >> input;

	if (input != "" && input[0] != '-')
	{
		val++;
		val = val + countPos();

	}
	else if (input != "" && input[0] == '-')
	{
		val = val + countPos();
	}
	else if (input == '')
	{
		return val;
	}
}
int main() 
{
	countPos();
}
