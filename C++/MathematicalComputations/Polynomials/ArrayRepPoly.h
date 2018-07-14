#ifndef _ARRAYREPPOLY_H_
#define _ARRAYREPPOLY_H_

#include "common.h"

using namespace std;
//template<T>
class ArrayRepPoly
{
    vector<int> _coeff;
    string _varname;
    void ClearLeadingZeros();
    void Error(const string&);
public:
    //rule of five stuff
    ArrayRepPoly(const ArrayRepPoly&) = default;               // Copy constructor
    ArrayRepPoly(ArrayRepPoly&&) = default;                    // Move constructor
    virtual ArrayRepPoly& operator=(const ArrayRepPoly&) & = default;  // Copy assignment operator
    virtual ArrayRepPoly& operator=(ArrayRepPoly&&) & = default;       // Move assignment operator
    virtual ~ArrayRepPoly() = default;								// Destructor

    //useful ctor/dtors
    ArrayRepPoly(vector<int>&,string);
    ArrayRepPoly(const vector<int>&,string,unsigned int);
    ArrayRepPoly();
    ArrayRepPoly(int*,string,unsigned int);

    //misc
    vector<int> Coeff(); //return a vector of coefficients

    //io operations
    friend ostream& operator<< ( ostream&,ArrayRepPoly& ); //print
    friend ostream& operator<< ( ostream&,const ArrayRepPoly& ); //print
    friend ostream& operator<< ( ostream&,ArrayRepPoly* ); //print
    string Name() const; 	//return a copy of the name

    //single polynomial operations
    double operator() (double) const; //evaluate
    double Evaluate(double) const; //evaluate
    unsigned int Order() const; //return the order of the polynomial
    int Term(unsigned int) const; //return the coefficient corresponding to an exponent or return zero
    //derivative
    ArrayRepPoly Derivative(); //newpoly = (d/dx)(poly)
    ArrayRepPoly IntegerPow(unsigned int); //newpoly = (poly)^power
    //finite difference?
    //finite difference quotients?
    //interpolate?

    //operations on two polynomials
    ArrayRepPoly& operator+= (const ArrayRepPoly&); //poly1 += poly2
    ArrayRepPoly& operator-= (const ArrayRepPoly&); //poly1 -= poly2
    ArrayRepPoly operator+ (const ArrayRepPoly&); //newpoly = poly1 + poly2
    ArrayRepPoly operator- (const ArrayRepPoly&); //newpoly = poly1 + poly2
    ArrayRepPoly& operator*= (const ArrayRepPoly&); //poly1 *= poly2
    ArrayRepPoly operator* (const ArrayRepPoly&); //newpoly = poly1 * poly2

    //polynomial operations involving nonpolynomials
    void Scale(double); //poly1 = poly1 * double1 (no return)
    ArrayRepPoly& operator*= (const double); //poly += dbl
    friend ArrayRepPoly operator* (double,const ArrayRepPoly&); // dbl * poly
    ArrayRepPoly operator* (const double); // poly * dbl
};

#endif
