#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
#include <vector>
using namespace std;

class VarExp; //forward decl

//The context class is mainly used for mapping VarExp's to boolean values
class Context
{
    map<string, bool> _map;
public:
    bool Lookup(const char*) const;
    void DefaultAssign(const char*);	//register a string and a name to a default value
    void Assign(VarExp*, bool);	//calling this with anything other than a varexp would make no sense
    void AssignValues();
    void AssignCombination(vector<bool>&);  //receive a combination of boolean values and assign them to each variable
    int VarCount();	//return the count of variables in the map
    void DumpContext();
};
#endif
