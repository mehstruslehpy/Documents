#ifndef _BOOLEXP_H_
#define _BOOLEXP_H_

#include <iostream>
#include <fstream>
#include "context.h"

using namespace std;

class BoolExp
{
public:
    BoolExp ( );				//ctor
    //BoolExp ( const char*);	//for passing a wff as a string
    //BoolExp ( const BoolExp& );	//copy ctor
    virtual ~BoolExp ( );

    //BoolExp& operator= ( const BoolExp& ); //for assignment
	//virtual void Print() const = 0;
	virtual string Name() const = 0;
	virtual bool Evaluate(Context&) = 0;
	virtual BoolExp* Replace(const char*, BoolExp&) = 0;
	virtual BoolExp* Copy() const = 0;
};
#endif
