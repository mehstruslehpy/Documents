#include "definitions.h"

using namespace std;

///allocate a single entry
void initEntry(Entry& temp)
{
    int count;  ///the number of fields the user wants
    int type;   ///the type of any given field
    string input; ///input
    string prologCode = ""; ///the inline asm for the function prolog goes here

    cout << "How many fields would you like in this structure?" << endl;
    getline(cin,input);
    count = atoi(input.c_str()); ///convert it to an integer

    temp.count = count;
    temp.values = new Value[count];

    ///initialize each field
    for(int i = 0; i < count; i++)
    {
        ///field name
        cout << "Enter the name of field "  << i << ": ";
        getline(cin,input);
        temp.values[i].fieldName = input;

        ///field type
        do
        {
            cout << "Enter the type for field " << i << ":" << endl;
            cout << "\t0 => integer" << endl;
            cout << "\t1 => float" << endl;
            cout << "\t2 => text" << endl;
            getline(cin,input);
            type = atoi(input.c_str());
        }
        while (type < 0 || type > 3);
        temp.values[i].type = type; ///convert it to an integer

        cout << "Enter a value for field " << i << ": ";
        if (temp.values[i].type == 0)  ///an int
        {
            getline(cin,input);
            temp.values[i].integer = atoi(input.c_str());
        }
        else if (temp.values[i].type == 1) ///a floating point number
        {
            getline(cin,input);
            temp.values[i].integer = atof(input.c_str());
        }
        else                                ///a string/text
        {
            getline(cin,input);
            temp.values[i].text = input;
        }
    }
    ///return temp;
}

///print a single entry
void displayEntry(Entry& entry)
{
    int count = entry.count;

    ///print each field
    for(int i = 0; i < count; i++)
    {
        cout << "\tMember: " << i << endl;
        cout << "\t\t" << entry.values[i].fieldName << ": ";
        if (entry.values[i].type == INT )  ///an int
        {
            cout << entry.values[i].integer << endl;
        }
        else if (entry.values[i].type == FLOAT) ///a floating point number
        {
            cout << entry.values[i].integer<< endl;
        }
        else if (entry.values[i].type == TEXT) ///a string/text
        {
            cout << entry.values[i].text<< endl;
        }
        else
        {
            cout << "Error: I don't know how to print that!" << endl;
        }
    }
}

///initialize the whole database at once
Entry* initDB(int count)
{

    Entry* db = new Entry[count];   ///this is a whole database of count entries

    ///initialize it
    for (int i = 0; i < count; i++)
    {
        cout << "Initializing entry " << i << " in the structure" << endl;
        initEntry(db[i]);
    }
    return db;
}

///print every single entry
void printDB(Entry* db, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "Printing entry " << i << " in the structure" << endl;
        displayEntry(db[i]);
    }
}


