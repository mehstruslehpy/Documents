#ifndef _BOOLEXP_H_
#define _BOOLEXP_H_

#include <iostream>
#include <fstream>
#include "context.h"

//need to fwd declare this for BoolReturn
class BoolExp;

//an enum for each proposition type possible
enum PropType {OR_EXP,VAR_EXP,NOT_EXP,AND_EXP,COND_EXP};

struct BoolReturn
{
    BoolReturn(BoolExp*,BoolExp*);
    BoolExp* op1;
    BoolExp* op2;
};

using namespace std;

//a boolean expression is a virtual parent class for all the other expression types
class BoolExp
{
    PropType _type;
public:
    BoolExp (PropType);				//ctor
    //BoolExp ( const char*);	//for passing a wff as a string
    //BoolExp ( const BoolExp& );	//copy ctor
    virtual ~BoolExp ( );

    //BoolExp& operator= ( const BoolExp& ); //for assignment
    //virtual void Print() const = 0;

    //return the name of the formula by calling this method on nested boolexp's
    virtual string Name() const = 0;
    //evaluate the value of the formula in the same manner
    virtual bool Evaluate(Context&) = 0;
    //replace the current formula
    virtual BoolExp* Replace(const char*, BoolExp&) = 0;
    virtual BoolExp* Copy() const = 0;
    //return the type of the outermost formula
    virtual PropType Type() const;
    //Infer from the current formula
    virtual BoolReturn Infer() = 0;
};

#endif
