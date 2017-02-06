#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	//this comment and all lines that don't contain exponentiation 
	//should be left intact
	//you can escape exponential translation by using //bitwise comments as shown
	//sadly the formatting of the exponential expressions gets smashed up	
	int x = 1; 
	int	y = 2; 
	int	z = 3; 
	int	a = 4;
	int	b = 5;
	int	c = 0;
	
	//do some math
	c = 1+2+3+4+5;
	//bitwise and expression on next line skip me!
	z = a ^ b;

	//do more math
	y = 111^222 * 333^444;
	x = (1+2) + (111+222)^333;
	b = 111^ ( x+y+z );

	a = x^y + y^z;

	//output some numbers
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
	return 0;
}
