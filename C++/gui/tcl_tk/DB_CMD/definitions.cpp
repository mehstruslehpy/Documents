#include "definitions.h"

using namespace std;

///read the database into memory, allocate entries on the heap etc..
Person* readDb(fstream& fileptr, string filename)
{
    int lclsize=0;
    Person* temp = NULL;
    string tempstr;
    string garbage;
    cout << "Attempting to open: " << filename << endl;
    fileptr.open(filename.c_str(), ios::in);
    if(fileptr.fail())
    {
        cout << "ERROR: database " << filename << " does not exist" << endl;
    }
    else
    {
        ///just in case these are not set correctly
        ///it will be a good idea to reset them..
        fileptr.clear();
        fileptr.seekg(0, ios::beg);

        ///a rudimentary line count
        for (int i = 1; getline(fileptr,garbage); i++) lclsize = i;
        lclsize /= FIELDS;

        ///now that we have a line count we must reset the fail bit
        ///and seek to the start
        fileptr.clear();
        fileptr.seekg(0, ios::beg);


        cout << "so far you have " << lclsize << " entries" << endl;
        temp = new Person[lclsize]();

        ///if we always set this on the first one we will always know how large our database is
        temp[0].db_size = lclsize;

        ///gather all the entries into memory

        cout << "Reading entries "<< endl;
        for(int i = 0; i < lclsize; i++)
        {
            ///name
            getline(fileptr, temp[i].name);

            ///age
            getline(fileptr, tempstr);
            temp[i].age = atoi(tempstr.c_str());

            ///personId
            getline(fileptr, tempstr);
            temp[i].personID = atoi(tempstr.c_str());

            ///rating
            getline(fileptr, tempstr);
            temp[i].rating = atoi(tempstr.c_str());

            ///phone number
            getline(fileptr, temp[i].phone);

            ///address
            getline(fileptr, temp[i].address);

            ///notes
            getline(fileptr, temp[i].info);
        }
    }
    fileptr.close();
    return temp;
}
///tag an entry onto the end of the file and increment the total count
int addEntry(fstream& fileptr, string filename, int size)
{
    Person temp;
    int state = 0;  ///-1 is bad 1 is good 0 we don't know
    int linecount = 0;
    string garbage;

    fileptr.open(filename.c_str(), ios::in | ios::out );
    if(fileptr.fail())
    {
        fileptr.open(filename.c_str(), ios::out );
        fileptr.close();
        fileptr.open(filename.c_str(), ios::in | ios::out );
    }
    fileptr.clear();
    fileptr.seekp(0, ios::beg);

    if (fileptr.fail())
    {
        cout << "Something went wrong appending your file!" << endl;
        state = -1;
    }
    else
    {
        ///a rudimentary line count
        for (int i = 0; (fileptr >> garbage); i++) linecount = i;
        cout <<"Line count of file: " << linecount << endl;
        fileptr.clear();
        fileptr.seekg(0, ios::end);

        ///take an entry as input
        cout << "Enter your persons name: ";
        getline(cin, temp.name);

        cout << "Enter " << temp.name << "s age: ";
        cin >> temp.age;

        do
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Between 1-10 enter how often you contact this person: ";
            cin >> temp.rating;
        }
        while(temp.rating < 1 || temp.rating > 10);

        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        do
        {
            cin.clear();
            cout << "Enter a phone number for " << temp.name << " with format: XXX-XXX-XXXX" << endl;
            getline(cin,temp.phone);
        }
        while(!validatePhone(temp.phone));

        cout << "Enter an address or location for " << temp.name << endl;
        getline(cin,temp.address);

        cout << "Enter any other descriptive info for " << temp.name << endl;
        getline(cin,temp.info);

        ///person id
        temp.personID = size+1;
        cout << "Person ID: " << temp.personID << endl;

        fileptr << temp.name << endl;
        fileptr << temp.age << endl;
        fileptr << temp.personID << endl;
        fileptr << temp.rating << endl;
        fileptr << temp.phone << endl;
        fileptr << temp.address << endl;
        fileptr << temp.info << endl;
        state = 1;
    }

    ///clear any leftover empty lines
    fileptr.clear();
    fileptr.seekg(0, ios::beg);
    linecount = 1;
    garbage = "";
    ///this could be used to delete trailing garbage if necessary
//    while ( getline( fileptr, garbage ) )
//    {
//        if ( garbage.empty() )
//        {
//            cout << "end at line" << linecount << endl;
//        }
//        linecount++;
//    }

    fileptr.close();
    return state;
}

///a really dumb way to validate phone numbers
bool validatePhone(string number)
{
    bool returnVal = false;
    ///check that all these things are true
    if(     number.size() == 12    &&///the length has to be correct
            isdigit(number.at(0))  &&///check digit
            isdigit(number.at(1))  &&
            isdigit(number.at(2))  &&
            number.at(3) == '-'    &&///check first dash
            isdigit(number.at(4))  &&
            isdigit(number.at(5))  &&
            isdigit(number.at(6))  &&
            number.at(7) == '-'    &&///check second dash
            isdigit(number.at(8))  &&
            isdigit(number.at(9))  &&
            isdigit(number.at(10)) &&
            isdigit(number.at(11))
      )
    {
        /// if they are all true return true else return false..
        returnVal = true;
    }
    return returnVal;
}

///this is all stuff for after we have read the database in
void dumpEntries(Person* people, int size)
{
    cout << "Dump of all entries:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout <<"Entry " << i << " name: " << people[i].name << endl;
        cout << "\t" << "age:  " << people[i].age << endl;
        cout << "\t" << "person ID:  " << people[i].personID << endl;
        cout << "\t" << "rating:  " << people[i].rating << endl;
        cout << "\t" << "phone number:  " << people[i].phone << endl;
        cout << "\t" << "address:  " << people[i].address << endl;
        cout << "\t" << "notes:  " << people[i].info << endl;
    }
}

void sortPerson(fstream& fileptr,string filename, Person* people,int& lastSort, int size,int cmdMode)
{
    fileptr.open(filename.c_str(), ios::in | ios::out|ios::trunc);
    if(fileptr.fail())
    {
        fileptr.open(filename.c_str(), ios::out );
        fileptr.close();
        fileptr.open(filename.c_str(), ios::in | ios::out | ios::trunc );
    }
    fileptr.clear();
    fileptr.seekp(0, ios::beg);

    if (people == NULL)
    {
        cout << "Error: you have not loaded a database yet." << endl;
    }
    else
    {

        string choice;
        int choicenum;
        if (cmdMode == -1)
        {
            cout << "Choose a field to sort by" << endl;
            cout << "\tname   (0)\n";
            cout << "\tage    (1)\n";
            cout << "\tID     (2)\n";
            cout << "\trating (3)\n";
            cout << "\tphone  (4)\n";
            cout << "\taddress(5)\n";
            cout << "\tinfo   (6)\n";
            cout << "> ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            lastSort = choicenum;
        }
        else
        {
            choicenum = cmdMode;
            lastSort = -1;
        }
        ///choose which sort to invoke based on what the user chose
        switch(choicenum)
        {
        case AGE:
            sortAge(people,size);
            break;
        case PERSON_ID:
            sortID(people,size);
            break;
        case RATING:
            sortRating(people,size);
            break;
        case NAME:
            sortName(people,size);
            break;
        case PHONE:
            sortPhone(people,size);
            break;
        case ADDRESS:
            sortAddr(people,size);
            break;
        case INFO:
            sortInfo(people,size);
            break;
        default:
            cout << "Error: sorry I don't know that kind of sort" << endl;
        }
    }
    cout << "rewriting the database" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << '.';
        fileptr << people[i].name << endl;
        fileptr << people[i].age << endl;
        fileptr << people[i].personID << endl;
        fileptr << people[i].rating << endl;
        fileptr << people[i].phone << endl;
        fileptr << people[i].address << endl;
        fileptr << people[i].info << endl;
    }
    fileptr.close();
    cout << endl;
}
int findPerson(Person* people,int& lastSort, int size)
{
    int returnIndex = -1;

    if (people == NULL)
    {
        cout << "Error: you have not loaded a database yet." << endl;
    }
    else
    {
        string choice;
        int choicenum;
        cout << "Choose a field to search by" << endl;
        cout << "\tname   (0)\n";
        cout << "\tage    (1)\n";
        cout << "\tID     (2)\n";
        cout << "\trating (3)\n";
        cout << "\tphone  (4)\n";
        cout << "\taddress(5)\n";
        cout << "\tinfo   (6)\n";
        cout << "> ";
        getline(cin,choice);
        choicenum = atoi(choice.c_str());
        ///choose which sort to invoke based on what the user chose
        switch(choicenum)
        {
        case AGE:
            if (lastSort!= AGE)
            {
                cout << "The last sort was not by age, sorting by age now" << endl;
                sortAge(people,size);
                lastSort = AGE;
            }
            cout << "Enter the age you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            returnIndex = searchAge(people,choicenum,size);
            break;
        case PERSON_ID:
            if (lastSort!= PERSON_ID)
            {
                cout << "The last sort was not by ID, sorting by ID now" << endl;
                sortID(people,size);
                lastSort = PERSON_ID;
            }
            cout << "Enter the ID you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            returnIndex = searchID(people,choicenum,size);
            break;
        case RATING:
            if (lastSort!= RATING)
            {
                cout << "The last sort was not by rating, sorting by rating now" << endl;
                sortRating(people,size);
                lastSort = RATING;
            }
            cout << "Enter the rating you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            returnIndex = searchRating(people,choicenum,size);
            break;
        case NAME:
            if (lastSort!= NAME)
            {
                cout << "The last sort was not by name, sorting by name now" << endl;
                sortName(people,size);
                lastSort = NAME;
            }
            cout << "Enter the name you wish to find: ";
            getline(cin,choice);
            returnIndex = searchName(people,choice,size);
            break;
        case PHONE:
            if (lastSort!= PHONE)
            {
                cout << "The last sort was not by phone number, sorting by phone number now" << endl;
                sortPhone(people,size);
                lastSort = PHONE;
            }
            cout << "Enter the phone number you wish to find: ";
            getline(cin,choice);
            returnIndex = searchPhone(people,choice,size);
            break;
        case ADDRESS:
            if (lastSort!= ADDRESS)
            {
                cout << "The last sort was not by address, sorting by address now" << endl;
                sortAddr(people,size);
                lastSort = ADDRESS;
            }
            cout << "Enter the address you wish to find: ";
            getline(cin,choice);
            returnIndex = searchAddress(people,choice,size);
            break;
        case INFO:
            if (lastSort!= INFO)
            {
                cout << "The last sort was not by informational entry, sorting by info now" << endl;
                sortID(people,size);
                lastSort = INFO;
            }
            cout << "Enter the information-entry you wish to find: ";
            getline(cin,choice);
            returnIndex = searchInfo(people,choice,size);
            break;
        default:
            cout << "Error: sorry I don't know that kind of search" << endl;
        }
    }
    return returnIndex;
}

void printPerson(Person* people, int i)
{
    if(people == NULL)
    {
        cout << "ERROR: You have not loaded a database yet" << endl;
    }
    else
    {
        cout <<"Entry " << i << " name: " << people[i].name << endl;
        cout << "\t" << "age:  " << people[i].age << endl;
        cout << "\t" << "person ID:  " << people[i].personID << endl;
        cout << "\t" << "rating:  " << people[i].rating << endl;
        cout << "\t" << "phone number:  " << people[i].phone << endl;
        cout << "\t" << "address:  " << people[i].address << endl;
        cout << "\t" << "notes:  " << people[i].info << endl;
    }
}
void printMenu()
{
    cout << endl;
    cout << "MENU:" << endl;
    cout << "\ta/A to add an entry" << endl;
    cout << "\tr/R read the database" << endl;
    cout << "\td/D print all entries" << endl;
    cout << "\tp/P print a single entry" << endl;
    cout << "\ts/S sort the database" << endl;
    cout << "\tf/F find an entry" << endl;
    cout << "\tw/W save state to disk" << endl;
    cout << "\tq/Q to quit" << endl;
}
///I should have made this earlier, it could probably be used to save some lines of code
///but I realized this too late
void writeDatabase(fstream& fileptr, string filename, Person* people, int size)
{
    fileptr.open(filename.c_str(), ios::in | ios::out| ios::trunc);
    if(fileptr.fail())
    {
        fileptr.open(filename.c_str(), ios::out );
        fileptr.close();
        fileptr.open(filename.c_str(), ios::in | ios::out | ios::trunc );
    }
    fileptr.clear();
    fileptr.seekp(0, ios::beg);

    if (people == NULL)
    {
        cout << "Error: you have not loaded a database yet." << endl;
    }
    else
    {
        cout << "Writing" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << '.';
            fileptr << people[i].name << endl;
            fileptr << people[i].age << endl;
            fileptr << people[i].personID << endl;
            fileptr << people[i].rating << endl;
            fileptr << people[i].phone << endl;
            fileptr << people[i].address << endl;
            fileptr << people[i].info << endl;
        }
        fileptr.close();
        cout << endl;
    }
}
int cmdModeFindPerson(Person* people, int size, int searchType, string choice)
{
    cout << "Warning: your search will fail if not already sorted correctly." << endl;
    int returnIndex = -1;

    if (people == NULL)
    {
        cout << "Error: you have not loaded a database yet." << endl;
    }
    else
    {
        int choicenum = -1;
        ///choose which sort to invoke based on what the user chose
        switch(searchType)
        {
        case AGE:
            choicenum = atoi(choice.c_str());
            cout << "choicenum" << choicenum << endl;
            returnIndex = searchAge(people,choicenum,size);
            break;
        case PERSON_ID:
            choicenum = atoi(choice.c_str());
            returnIndex = searchID(people,choicenum,size);
            break;
        case RATING:
            choicenum = atoi(choice.c_str());
            returnIndex = searchRating(people,choicenum,size);
            break;
        case NAME:
            returnIndex = searchName(people,choice,size);
            break;
        case PHONE:
            returnIndex = searchPhone(people,choice,size);
            break;
        case ADDRESS:
            returnIndex = searchAddress(people,choice,size);
            break;
        case INFO:
            returnIndex = searchInfo(people,choice,size);
            break;
        default:
            cout << "Error: sorry I don't know that kind of search" << endl;
        }
    }
    return returnIndex;
}
/*
**  below this point is a ton of duplicated code because I could not think of
**  for the sort and search functions, this is a bit more simple in the version
**  using lambda functions
**/
///pretty much modified from here
///http://www.algolist.net/Algorithms/Sorting/Insertion_sort
void sortAge(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].age > people[j].age)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortID(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].personID > people[j].personID)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortRating(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].rating < people[j].rating)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortName(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].name > people[j].name)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortPhone(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].phone > people[j].phone)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortAddr(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].address > people[j].address)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

void sortInfo(Person* people,int length)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;
        while (j > 0 && people[j - 1].info > people[j].info)
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

/**
*** here is binary search for various members
*/

///pg 461 of the book has the unmodified version of this algo
int searchAge(Person* arr, int value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].age == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].age > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int searchID(Person* arr, int value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].personID == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].personID > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int searchRating(Person* arr, int value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].rating == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].personID > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int searchName(Person* arr, string value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].name == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].name > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int searchPhone(Person* arr, string value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].phone == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].phone > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int searchAddress(Person* arr, string value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].address == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].address > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

int searchInfo(Person* arr, string value, int size)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (arr[middle].info == value)
        {
            found = true;
            position = middle;
        }
        else if (arr[middle].info > value)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
