#include "definitions.h"

using namespace std;
///read the database in, allocate entries on the heap etc..
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
        for(int i = 0; i < lclsize; i++)
        {
            ///name
            getline(fileptr, temp[i].name);
            cout << "Reading entry " << i << " name: " << temp[i].name << endl;
            ///age
            getline(fileptr, tempstr);
            temp[i].age = atoi(tempstr.c_str());
            cout << "Reading entry " << i << " age: " << temp[i].age << endl;
            ///personId
            getline(fileptr, tempstr);
            temp[i].personID = atoi(tempstr.c_str());
            cout << "Reading entry " << i << " Person ID: " << temp[i].personID << endl;
            ///rating
            getline(fileptr, tempstr);
            temp[i].rating = atoi(tempstr.c_str());
            cout << "Reading entry " << i << " rating: " << temp[i].rating << endl;
            ///phone number
            getline(fileptr, temp[i].phone);
            cout << "Reading entry " << i << " phone number: " << temp[i].phone << endl;
            ///address
            getline(fileptr, temp[i].address);
            cout << "Reading entry " << i << " address: " << temp[i].address << endl;
            ///notes
            getline(fileptr, temp[i].info);
            cout << "Reading entry " << i << " address: " << temp[i].info << endl;
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
///    while ( getline( fileptr, garbage ) )
///    {
///        if ( garbage.empty() )
///        {
///            cout << "end at line" << linecount << endl;
///        }
///        linecount++;
///    }

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

///print all the stuff after we have read the database in
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

///a wrapper function that allows the user to choose a sorting function then sorts the database
///this one has some cool lambda stuff
void sortPerson(fstream& fileptr,string filename, Person* people,int& lastSort, int size)
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
        ///choose which sort to invoke based on what the user chose
        switch(choicenum)
        {
        case AGE:
        {
            ///because we are creating variables in a case statement we need braces here
            ///https://stackoverflow.com/questions/39465121/gcc-error-when-using-a-switch-statement-with-a-default-case-and-a-lambda-functio#39465201

            ///[&] (params...) ->optional_returntype {stmts..} is used to signify a lambda function with a capture,
            ///our lambda function performs a comparison on specific members of a struct passed in

            /// all this allows us to choose the members of our structure to use for sorting from outside the function
            ///using this method we only need to make one function to perform the sorting
            ///we can then pass into that function a lambda function to specify the comparison to sort by

            ///auto will match the type for ageCompare to this:
            ///std::function<int (const Person&, const Person&)>
            ///we don't exactly need to specify a return type thru: "-> int" but it is more explicit looking
            std::function<int (const Person&, const Person&)> ageCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.age > p2.age);
            };

            ///pass the lambda function into insertion sort
            insertionSort(people,size,ageCompare);
            ///MORE INFO:
            ///http://en.cppreference.com/w/cpp/language/lambda
            ///http://www.cprogramming.com/c++11/c++11-lambda-closures.html
            ///https://blog.feabhas.com/2014/03/demystifying-c-lambdas/
        }
        break;
        case PERSON_ID:
        {
            ///I have no idea the right way to format a lambda function in c++ so I tried
            ///to match the way you would do it with a normal function
            std::function<int (const Person&, const Person&)> idCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.personID > p2.personID);
            };
            insertionSort(people,size,idCompare);
        }
        break;
        case RATING:
        {
            std::function<int (const Person&, const Person&)> ratingCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.rating > p2.rating);
            };
            insertionSort(people,size,ratingCompare);
        }
        break;
        case NAME:
        {
            std::function<int (const Person&, const Person&)> nameCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.name > p2.name);
            };
            insertionSort(people,size,nameCompare);
        }
        break;
        case PHONE:
        {
            std::function<int (const Person&, const Person&)> phoneCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.phone > p2.phone);
            };
            insertionSort(people,size,phoneCompare);
        }
        break;
        case ADDRESS:
        {
            std::function<int (const Person&, const Person&)> addressCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.address > p2.address);
            };
            insertionSort(people,size,addressCompare);
        }
        break;
        case INFO:
        {
            std::function<int (const Person&, const Person&)> infoCompare =
                [&](const Person &p1, const Person &p2) -> int
            {
                return (p1.info > p2.info);
            };
            insertionSort(people,size,infoCompare);
        }
        break;
        default:
            cout << "Error: sorry I don't know that kind of sort" << endl;
        }
    }
    fileptr.close();
    writeDatabase(fileptr,filename,people,size);
    cout << endl;
}

///another wrapper but this time it asks the user for a field to search by
///this also has some cool lambda junk
int findPerson(Person* people,int& lastSort, int size)
{
    int returnIndex = -1;

    if (people == NULL)
    {
        cout << "Error: you have not loaded a database yet." << endl;
    }
    else
    {
        ///int numValue;
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
        {
            if (lastSort!= AGE)
            {
                cout << "The last sort was not by age, sorting by age now" << endl;
                std::function<int (const Person&, const Person&)> ageCompare =
                    [&](const Person &p1, const Person &p2) -> int
                {
                    return (p1.age > p2.age);
                };
                insertionSort(people,size,ageCompare);
                lastSort = AGE;
            }
            cout << "Enter the age you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            std::function<int (const Person&, const int&)> age =
                [&](const Person &p1, const int &value) -> int
            {   ///a kind of snazzy way to do nested ternaries to get a three valued comparison
                ///if                    else if                 else
                return (p1.age > value) ? 1 : (p1.age == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choicenum,size,age);
            break;
        }
        case PERSON_ID:
        {
            if (lastSort!= PERSON_ID)
            {
                cout << "The last sort was not by ID, sorting by ID now" << endl;
                std::function<int (const Person&, const Person&)> idCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.personID > p2.personID);};
                insertionSort(people,size,idCompare);
                lastSort = PERSON_ID;
            }
            cout << "Enter the ID you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            std::function<int (const Person&, const int&)> person_id =
                [&](const Person &p1, const int &value) -> int
            {
                ///if                    else if                 else
                return (p1.personID > value) ? 1 : (p1.personID == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choicenum,size,person_id);
            break;
        }
        case RATING:
        {
            if (lastSort!= RATING)
            {
                cout << "The last sort was not by rating, sorting by rating now" << endl;
                std::function<int (const Person&, const Person&)> ratingCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.rating > p2.rating);};
                insertionSort(people,size,ratingCompare);
                lastSort = RATING;
            }
            cout << "Enter the rating you wish to find: ";
            getline(cin,choice);
            choicenum = atoi(choice.c_str());
            std::function<int (const Person&, const int&)> rating =
                [&](const Person &p1, const int &value) -> int
            {
                ///if                    else if                 else
                return (p1.rating > value) ? 1 : (p1.rating == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choicenum,size,rating);
            break;
        }
        case NAME:
        {
            if (lastSort!= NAME)
            {
                cout << "The last sort was not by name, sorting by name now" << endl;
                std::function<int (const Person&, const Person&)> nameCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.name > p2.name);};
                insertionSort(people,size,nameCompare);
                lastSort = NAME;
            }
            cout << "Enter the name you wish to find: ";
            getline(cin,choice);
            std::function<int (const Person&, const string&)> name =
                [&](const Person &p1, const string &value) -> int
            {
                ///if                    else if                 else
                return (p1.name > value) ? 1 : (p1.name == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choice,size,name);
        }
        break;
        case PHONE:
        {
            if (lastSort!= PHONE)
            {
                cout << "The last sort was not by phone number, sorting by phone number now" << endl;
                std::function<int (const Person&, const Person&)> phoneCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.phone > p2.phone);};
                insertionSort(people,size,phoneCompare);
                lastSort = PHONE;
            }
            cout << "Enter the phone number you wish to find: ";
            getline(cin,choice);
            std::function<int (const Person&, const string&)> phone =
                [&](const Person &p1, const string &value) -> int
            {
                ///if                    else if                 else
                return (p1.phone > value) ? 1 : (p1.phone == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choice,size,phone);
            break;
        }
        case ADDRESS:
        {
            if (lastSort!= ADDRESS)
            {
                cout << "The last sort was not by address, sorting by address now" << endl;
                std::function<int (const Person&, const Person&)> addressCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.address > p2.address);};
                insertionSort(people,size,addressCompare);
                lastSort = ADDRESS;
            }
            cout << "Enter the address you wish to find: ";
            getline(cin,choice);
            std::function<int (const Person&, const string&)> address =
                [&](const Person &p1, const string &value) -> int
            {
                ///if                    else if                 else
                return (p1.address > value) ? 1 : (p1.address == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choice,size,address);
            break;
        }
        case INFO:
        {
            if (lastSort!= INFO)
            {
                cout << "The last sort was not by informational entry, sorting by info now" << endl;
                std::function<int (const Person&, const Person&)> infoCompare
                    = [&](const Person &p1, const Person &p2) -> int {return (p1.info > p2.info);};
                insertionSort(people,size,infoCompare);
                lastSort = INFO;
            }
            cout << "Enter the information-entry you wish to find: ";
            getline(cin,choice);
            std::function<int (const Person&, const string&)> info =
                [&](const Person &p1, const string &value) -> int
            {
                ///if                    else if                 else
                return (p1.info> value) ? 1 : (p1.info == value ? 0 : -1 );
            };
            returnIndex = binarySearch(people,choice,size,info);
            break;
        }
        default:
            cout << "Error: sorry I don't know that kind of search" << endl;
        }
    }
    return returnIndex;
}

///print a single person
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
///repl menu
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
///I should have made this earlier, writes the whole database in mem to the disk
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
        cout << "Writing changes to disk" << endl;
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

///pretty much modified from here
///http://www.algolist.net/Algorithms/Sorting/Insertion_sort
///but it accepts a lambda function to perform comparisons, and uses my structure
///see the calling function for more info
void insertionSort(Person* people,int length, std::function<int (const Person&, const Person&)> compare)
{
    int i, j;
    Person tmp;
    for (i = 1; i < length; i++)
    {
        j = i;          ///compare is a lambda function to be passed in by the caller
        while (j > 0 && compare(people[j - 1], people[j]))
        {
            tmp = people[j];
            people[j] = people[j - 1];
            people[j - 1] = tmp;
            j--;
        }
    }
}

///pg 461 of the book has the unmodified version of this algorithm
///the main interesting thing here is that the lambda function must return one of three values (technically two)
///see below for the specifics on that
int binarySearch(Person* arr, int value, int size, std::function<int (const Person&,const int&)> compare)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (compare(arr[middle], value) == 0)    ///check if equal => compare returns 0 for equal
        {
            found = true;
            position = middle;
        }
        else if (compare(arr[middle], value) == 1)   ///check if greater => compare returns 1 for greater
            last = middle - 1;
        else
            first = middle + 1;                 ///compare would return -1 for less than if we needed it
    }
    return position;
}

///this is an overload of the last function  for when a string is passed in
///there is probably a way to narrow this down to one search function with templates or something
int binarySearch(Person* arr, string value, int size, std::function<int (const Person&,const string&)> compare)
{
    int first = 0;
    int last = size - 1;
    int middle;
    int position = -1; ///negative one means not found
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first+last) / 2;
        if (compare(arr[middle], value) == 0)    ///check if equal => compare returns 0 for equal
        {
            found = true;
            position = middle;
        }
        else if (compare(arr[middle], value) == 1)   ///check if greater => compare returns 1 for greater
            last = middle - 1;
        else
            first = middle + 1;                 ///compare would return -1 for less than if we needed it
    }
    return position;
}
