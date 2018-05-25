#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <iostream>
#include <map>
#include <stdlib.h>
#include <vector>
#include <memory>
using namespace std;

class VarExp; //forward decl

//The context class is mainly used for mapping VarExp's to boolean values
class Context
{
    map<string, bool> _map;
public:
    bool Lookup(string) const; //find the value of the input variable
    void DefaultAssign(string);	//register a string and a name to a default value
    void Assign(shared_ptr<VarExp>, bool);	//calling this with anything other than a varexp would make no sense
    void AssignValues(); //assign a value to each variable based on user input
    void AssignCombination(vector<bool>&);  //receive a combination of boolean values and assign them to each variable
    int VarCount();	//return the count of variables in the map
    void DumpContext();
};
#endif
