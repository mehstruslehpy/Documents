#ifndef _VAREXP_H_
#define _VArEXP_H_
#include "boolexp.h"
#include "context.h"
#include <string.h>	//cstring functions
using namespace std;

class VarExp : public BoolExp
{
    friend Context;	//makes life easier for Context
    char* _name;
public:
    //VarExp ( );				//ctor
    VarExp ( const char*);	//for passing a variable name as a string
    //VarExp ( const VarExp& );	//copy ctor
    virtual ~VarExp ( );

    //VarExp& operator= ( const VarExp& ); //for assignment
    virtual string Name() const; 	//return a copy of the name

    virtual bool Evaluate(Context&);
    virtual BoolExp* Replace(const char*, BoolExp&);	//these functions require dynamic memory
    virtual BoolExp* Copy() const;						//these functions require dynamic memory
    virtual BoolReturn Infer();
};
#endif
