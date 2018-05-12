#ifndef _CONDEXP_H_
#define _CONDEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class CondExp : public BoolExp
{
    BoolExp* _operand1;
    BoolExp* _operand2;
public:
    CondExp ( BoolExp*, BoolExp* );	//not expressions are constructed through boolean expressions
    virtual ~CondExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual BoolExp* Replace(const char*, BoolExp&);	//these functions require dynamic memory
    virtual BoolExp* Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};

#endif
