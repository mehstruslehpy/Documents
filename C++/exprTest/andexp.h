#ifndef _ANDEXP_H_
#define _ANDEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class AndExp : public BoolExp
{
    shared_ptr<BoolExp> _operand1;	//left operand
    shared_ptr<BoolExp> _operand2;	//right operand
public:
    AndExp ( shared_ptr<BoolExp>, shared_ptr<BoolExp> );	//not expressions are constructed through boolean expressions
    virtual ~AndExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual shared_ptr<BoolExp> Replace(string, BoolExp&);	//these functions require dynamic memory
    virtual shared_ptr<BoolExp> Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};

#endif
