//TODO:
// -Handle zero polynomial cases
// -Handle null polys
#include <iostream>
#include "ArrayRepPoly.h"
using namespace std;

int main()
{
    ArrayRepPoly myPoly1({1,3,9,22,31,8},"x",6);
    ArrayRepPoly myPoly2({1,2,13,6,7},"x",5);
    cout << "myPoly1: " << myPoly1 << endl;
	cout << "(d/dx)("<<myPoly1<<") = "<< myPoly1.Derivative() <<endl;
 	cout << endl;
    cout << "myPoly2: " << myPoly2 << endl;
	cout << "(d/dx)("<<myPoly2<<") = "<< myPoly2.Derivative() <<endl;
 	cout << endl;
	cout << "(myPoly1 * myPoly2)(22)" << (myPoly1*myPoly2).Evaluate(22) << endl;
    cout << "myPoly1*=myPoly2: " << (myPoly1 *= myPoly2) << endl;
 	cout << endl;
 	cout << "myPoly1*=myPoly2: " << (myPoly1 *= myPoly2) << endl;
 	cout << endl;
    cout << "myPoly1*=myPoly2: " << (myPoly1 *= myPoly2) << endl;
 	cout << endl;
    cout << "myPoly1*=myPoly2: " << (myPoly1 *= myPoly2) << endl;
 	cout << endl;
	cout << "myPoly1-=myPoly1:" << (myPoly1-=myPoly1) << endl;
	cout << "(myPoly1-=myPoly1)(2): " << (myPoly1-=myPoly1)(2) << endl;
	cout << "(myPoly1-myPoly1)(2): " << (myPoly1-myPoly1)(2) << endl;
	cout << endl;
    cout << "(x+1)^0 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(0) << endl;
	cout << "(x+1)^1 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(1) << endl;
	cout << "(x+1)^2 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(2) << endl;
	cout << "(x+1)^3 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(3) << endl;
	cout << "(x+1)^4 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(4) << endl;
	cout << "(x+1)^5 = " << ArrayRepPoly({1,1},"X",2).IntegerPow(5) << endl;
    cout << "zero poly a:" << ArrayRepPoly({0,2,3},"Y",0) << endl;
    //cout << "zero poly b:" << ArrayRepPoly({0},"Y",0) << endl;
    //cout << "mul zero poly"<< (ArrayRepPoly({0},"Y",0) *= 3.0) << endl; 
	//cout << "NULL POLY: " << ArrayRepPoly(NULL,"X",2) <<endl;       
    return 0;
}
