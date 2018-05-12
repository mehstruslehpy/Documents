#ifndef _ANDEXP_H_
#define _ANDEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class AndExp : public BoolExp
{
	BoolExp* _operand1;
	BoolExp* _operand2;
public:
    AndExp ( BoolExp*, BoolExp* );	//not expressions are constructed through boolean expressions
    virtual ~AndExp ( );

	virtual string Name() const; 	//return a copy of the name

	virtual bool Evaluate(Context&);
	virtual BoolExp* Replace(const char*, BoolExp&);	//these functions require dynamic memory
	virtual BoolExp* Copy() const;						//these functions require dynamic memory
};

#endif
