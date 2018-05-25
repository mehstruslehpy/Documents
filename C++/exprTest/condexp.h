#ifndef _CONDEXP_H_
#define _CONDEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class CondExp : public BoolExp
{
    shared_ptr<BoolExp> _operand1;
    shared_ptr<BoolExp> _operand2;
public:
    CondExp ( shared_ptr<BoolExp>, shared_ptr<BoolExp> );	//not expressions are constructed through boolean expressions
    virtual ~CondExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual shared_ptr<BoolExp> Replace(string, BoolExp&);	//these functions require dynamic memory
    virtual shared_ptr<BoolExp> Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};

#endif
