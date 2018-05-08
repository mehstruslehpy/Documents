#ifndef _NOTEXP_H_
#define _NOTEXP_H_
#include "boolexp.h"
#include <string.h>	//cstring functions

using namespace std;

class NotExp : public BoolExp
{
	BoolExp* _operand;
public:
    NotExp ( BoolExp*);	//not expressions are constructed through boolean expressions
    virtual ~NotExp ( );

	virtual string Name() const; 	//return a copy of the name

	virtual bool Evaluate(Context&);
	virtual BoolExp* Replace(const char*, BoolExp&);	//these functions require dynamic memory
	virtual BoolExp* Copy() const;						//these functions require dynamic memory
};

#endif
