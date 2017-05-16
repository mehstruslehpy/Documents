#ifndef FISH_H
#define FISH_H

#include <iostream>
using namespace std;

class Fish
{
private:
    string name;
    int value;
public:
    Fish();
    Fish(const string,const int);   ///see the note in
    void setName(const string);     ///the implementation for why this differs from the spec
    void setValue(const int);
    string getName();
    int getValue();
};

#endif ///FISH_H
