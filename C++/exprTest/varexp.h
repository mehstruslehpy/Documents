#ifndef _VAREXP_H_
#define _VArEXP_H_
#include "boolexp.h"
#include "context.h"
#include <string.h>	//cstring functions
using namespace std;

class VarExp : public BoolExp
{
    friend Context;	//makes life easier for Context
    string _name;
public:
    VarExp (string);	//for passing a variable name as a string
    virtual ~VarExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual shared_ptr<BoolExp> Replace(string, BoolExp&);	//these functions require dynamic memory
    virtual shared_ptr<BoolExp> Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};
#endif
