#ifndef _NOTEXP_H_
#define _NOTEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class NotExp : public BoolExp
{
    shared_ptr<BoolExp> _operand;
public:
    NotExp ( shared_ptr<BoolExp>);	//not expressions are constructed through boolean expressions
    virtual ~NotExp ( );

    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual shared_ptr<BoolExp> Replace(string, BoolExp&);	//these functions require dynamic memory
    virtual shared_ptr<BoolExp> Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};

#endif
