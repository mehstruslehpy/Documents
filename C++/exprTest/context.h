#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>

using namespace std;

class VarExp; //forward decl

//The context class is mainly used for mapping VarExp's to boolean values
class Context
{
    map<string, bool> _map;
public:
    bool Lookup(const char*) const;
    void Assign(VarExp*, bool);	//calling this with anything other than a varexp would make no sense
};
#endif
