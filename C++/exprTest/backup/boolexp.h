#ifndef _BOOLEXP_H_
#define _BOOLEXP_H_

#include <iostream>
#include <fstream>
#include "context.h"

//need to fwd declare this for BoolReturn
class BoolExp;

//typedef enum PropType {OR_EXP,VAR_EXP,NOT_EXP,AND_EXP,COND_EXP};
enum PropType {OR_EXP,VAR_EXP,NOT_EXP,AND_EXP,COND_EXP};

struct BoolReturn
{
    BoolReturn(BoolExp*,BoolExp*);
    BoolExp* op1;
    BoolExp* op2;
};

using namespace std;

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
    virtual string Name() const = 0;
    virtual bool Evaluate(Context&) = 0;
    virtual BoolExp* Replace(const char*, BoolExp&) = 0;
    virtual BoolExp* Copy() const = 0;
    virtual PropType Type() const;
    virtual BoolReturn Infer() = 0;
};

#endif
