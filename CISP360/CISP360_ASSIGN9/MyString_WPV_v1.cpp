#include <iostream>

using namespace std;

void printMenu();
void printList(int*, int);
int* expand(int*, int, int&);
void insertZero(int*, int, int);
///doing the function prototype like this makes more sense to me...
///https://stackoverflow.com/questions/9167540/dynamic-arrays-passing-to-functions
bool insertGrow(int* , int, int, int);
int main()
{
    bool growFlag = false;
    int choice;
    int c;
    int n;
    int size = 1;
    int *p = new int[size];
    int count = 0;

    cout << "Welcome to the integer storage program!" << endl;

    do
    {
        printMenu();

        cin >> choice;

        switch(choice)
        {

        case 1:
            cout << "Enter the integer to insert: ";
            cin >> c;
            if(size == count)
            {
                p = expand(p, count, size);
            }
            insertZero(p, c, count++);
                        printList(p, count);
            break;
        case 2:
            printList(p, count);
            break;
        case 3:
            do///keep running until the user enters a valid index
            {
                cout << "Enter an integer to insert: ";
                cin >> c;
                cout << "Enter an index to insert at:";
                cin >> n;
                if(size == count)
                {
                    p = expand(p, count, size);
                }
                growFlag = insertGrow(p,c,n,count);
            }
            while(!growFlag);
            cout << "DEBUG :D" << endl;
            count++;
            printList(p,count);
            break;
        default:
            cout << "Invalid menu choice." << endl;
            break;
        }


    }
    while(choice != 4);

    delete []p;
    return 0;
}

void insertZero(int *p, int c, int count)
{
    int prev = *p;
    int temp;
    for(int i = 1; i <= count; i++)
    {
        temp = *(p + i);
        *(p + i) = prev;
        prev = temp;
    }

    *p = c;
}

void printMenu()
{
    cout << "Please choose from the following menu choices:" << endl;
    cout << "1)  Insert a new element at the beginning of the list." << endl;
    cout << "2)  Print the contents of the list." << endl;
    cout << "3)  INSERT TO SPECIFIC INDEX." << endl;
    cout << "4)  Exit." << endl;

}

void printList(int *p, int count)
{
    cout << "Contents of the list: " << endl;
    for(int i = 0; i < count; i++)
    {
        cout << *(p + i) << " : ";
    }
    cout << endl;
}

int* expand(int *p, int count, int &size)
{
    size *= 2;
    cout << "Expanding the list.  New size: " << size << endl;
    int *temp = new int[size];

    for(int i = 0; i < count; i++)
    {
        *(temp + i) = *(p + i);
    }
    delete []p;
    return temp;
}
bool insertGrow(int *p, int input, int index, int count)
{
    int *temp = 0;
    bool growFlag = false;
    ///check that the user has chosen a valid index
    ///pass back the input list
    if (index > (count-1))
    {
        growFlag = false;
        temp = p;
    }
    int tempLast = *(p+count-1);///squirrel the last elem away temporarily
    cout << "Last is: " << tempLast<<endl;
    ///shift the whole array to the right by one...
    for (int i = index; i > count; i++)
    {
        *(p+i-1) = *(p+i);
    }
    *(p+count) = tempLast;    ///reset the last element
    p[index] = -99;
    growFlag = true;
    return growFlag;
};
