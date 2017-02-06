#include <iostream>

using namespace std;

int main()
{
	//this comment and all lines that don't contain exponentiation 
	//should be left intact
	//you can escape exponential translation by using //bitwise comments as shown
	//sadly the formatting of the exponential expressions gets smashed up	
	int x = 1, 
		y = 2, 
		z = 3, 
		a = 4,
		b = 5;
		c = 0;
	
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
