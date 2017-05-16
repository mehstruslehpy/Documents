#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <limits>
#include <unistd.h>

using namespace std;

///an enum to represent the types contained
enum {INT,FLOAT,TEXT,FUNC};

///a function looks like this
struct Function
{
    string args;        ///this just a bunch of arg types separated by spaces ex: "int, int, double, ..., char"
    string returnType;  ///this is a single return type ex: "int"
    string funcName;    ///the name of the function to be loaded
    string filename;    ///the location of the dll containing the function
    int (*intFunc)();
    double (*dblFunc)();
    char (*charFunc)();
};

///each Value can be one of three types
///each value will be aware of the type it contains
struct Value
{
    int type;   ///holds the type of this specific value/field (the enum above corresponds to this)
    string fieldName; ///the name of this field
    int integer;
    double decimal;
    string text;
    Function func;
};

///each Entry will be aware of the amount of fields it contains
struct Entry
{
    int count;
    Value* values;  ///this will be allocated dynamically
};


Entry* initDB(int);
void printDB(Entry*,int);

///single entry functions
///For the Entry structure I can use a "fake-constructor" type function
void initEntry(Entry&);
void displayEntry(Entry&);

///these are functions to do with generating functions
void dumbFunction();    ///this can read in a program from stdin and compile it
void genFunctionProlog(string, string&); ///this can read a certain sort of function specification to gen a func prolog

#endif
