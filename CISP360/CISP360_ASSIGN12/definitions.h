#ifndef DEFINITIONS_H
#define DEFINITIONS_H


#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <limits>
using namespace std;
///we can globally track the amount of entries to make life simpler
extern int SIZE;

///we will use sensible defaults, but doing this like this
///makes this updateable in main
extern string FILE_NAME;

///this can be used to track the amount of fields that are in our struct
///this does not count db_size as a field because that is just an administrative hack
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
void writeDatabase(fstream&, string, Person*, int);

///sort types
void sortAge(Person*,int);
void sortID(Person*,int);
void sortRating(Person*,int);
void sortName(Person*,int);
void sortPhone(Person*,int);
void sortAddr(Person*,int);
void sortInfo(Person*,int);

///search types
int searchAge(Person*,int,int);
int searchID(Person*,int,int);
int searchRating(Person*,int,int);
int searchName(Person*,string,int);
int searchPhone(Person*,string,int);
int searchAddress(Person*,string,int);
int searchInfo(Person*,string,int);

///more utility functions
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
