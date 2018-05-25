#ifndef _OREXP_H_
#define _OREXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class OrExp : public BoolExp
{
    shared_ptr<BoolExp> _operand1;
    shared_ptr<BoolExp> _operand2;
public:
    OrExp ( shared_ptr<BoolExp>, shared_ptr<BoolExp> );	//not expressions are constructed through boolean expressions
    virtual ~OrExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual shared_ptr<BoolExp> Replace(string, BoolExp&);	//these functions require dynamic memory
    virtual shared_ptr<BoolExp> Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};

#endif
