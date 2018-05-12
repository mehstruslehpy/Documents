#ifndef _OREXP_H_
#define _OREXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class OrExp : public BoolExp
{
	BoolExp* _operand1;
	BoolExp* _operand2;
public:
    OrExp ( BoolExp*, BoolExp* );	//not expressions are constructed through boolean expressions
    virtual ~OrExp ( );

	virtual string Name() const; 	//return a copy of the name

	virtual bool Evaluate(Context&);
	virtual BoolExp* Replace(const char*, BoolExp&);	//these functions require dynamic memory
	virtual BoolExp* Copy() const;						//these functions require dynamic memory
};

#endif
