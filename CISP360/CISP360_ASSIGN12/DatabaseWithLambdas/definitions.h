#ifndef DEFINITIONS_H
#define DEFINITIONS_H


#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <limits>
#include <functional>
using namespace std;

///this can be used to track the amount of fields that are in our struct
///this does not count db_size as a field because that is just an administrative hack
///we use this throughout in definitions.cpp
const int FIELDS = 7;

struct Person
{
    int db_size;
    string name;
    int age;
    int personID;
    int rating;
    string phone;
    string address;
    string info;
};
///this will help us identify fields nicely in code
enum FIELDS
{
    NAME,
    AGE,
    PERSON_ID,
    RATING,
    PHONE,
    ADDRESS,
    INFO,

};

///basic database functions
Person* readDb(fstream&, string);
int addEntry(fstream&, string,int);

///this is all stuff for after we have read the database in
void dumpEntries(Person*, int);
void sortPerson(fstream&,string, Person*,int&, int); ///file pointer, filename person*, store prev sort type, size of array
int findPerson(Person*,int&, int);
void printPerson(Person*,int);

///I totally should have thought to do this early on but I am an idiot so there is a couple instances of this kind of code
///duplicated in some of the definitions.cpp file
void writeDatabase(fstream&, string, Person*, int);

///sort types
///these always return an int, takes two Person structure addresses, and a lambda function
///which will take two Person&'s and return one int back to the interior of the insertionSort function
void insertionSort(Person*, int, std::function<int (const Person&, const Person&)>);

///search types
///basically the same idea as above but modified for a binary search algorithm
///also we need an overload because we either search for strings OR integer values
int binarySearch(Person*, int,    int, std::function<int (const Person&,const int&)>);
int binarySearch(Person*, string, int, std::function<int (const Person&, const string&)>);

///some of the more boring utility functions
bool validatePhone(string);
void printMenu();
#endif

///DATABASE FILE STRUCTURE
///LINE NO:
///1: name
///2: age
///3: personID
///4: rating
///5: phone number
///6: address
///7: notes
