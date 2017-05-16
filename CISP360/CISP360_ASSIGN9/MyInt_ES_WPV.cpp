#include <iostream>

using namespace std;

///geewhizz allocation info
int ALLOCATED = 0;
void printMenu();
void printList(int*, int);
int* expand(int*, int&, int&);
int* shrink(int*, int&, int&);
void insertZero(int*, int, int);
bool insert(int*, int, int, int);
bool remove(int *p, int index, int count);
///the sort you're asking for will be done via selection sort
void sort(int *p, int size);

///helpers to implement quicksort
void sortquick(int *p, int size);
int partition(int *p, int lo, int hi);
void quickSort(int *p, int lo, int hi);

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
            cout << "Enter the integer to append: ";
            cin >> c;
            p = expand(p, count, size);
            insert(p,c,count-1,count);///insert at the beginning of the list
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            break;
        case 2:
            cout << "Enter the integer to insert: ";
            cin >> c;
            ///cout << "Pre count: " << count << endl; ///debugging
            p = expand(p, count, size);
            insertZero(p, c, count);
            ///cout << "Post count: " << count << endl; ///debugging
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size of the list: " << size << "." << endl << endl;
            break;
        case 3:
            growFlag = false;
            do///keep running until the user enters a valid index
            {
                cout << "Enter an integer to insert: ";
                cin >> c;
                cout << "Enter an index to insert at: ";
                cin >> n;
                p = expand(p, count, size);
                if (!(n > count) && !(n < 0))       ///kinda redundant since we also check this
                    growFlag = insert(p,c,n,count); ///inside of insert
            }while(!growFlag);
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            break;
        case 4:
            do
            {
                cout << "Enter the index to remove:" << endl;
                cin >> n;
            }while (n < 0 || n > count-1 );
            if (size > 1)
            {

                remove(p,n,count);
                p = shrink(p, count, size);
                cout << endl;
                printList(p, count);///debugging and status info
                cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            }
            else
            {
                cout << endl << "Your array is already empty." << endl << endl;
            }
            break;
        case 5:
            sort(p, count);
            cout << endl;
            cout << "Your array has been sorted with selection sort" << endl;
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            break;
        case 6:
            sortquick(p, count);
            cout << endl;
            cout << "Your array has been sorted with quick sort" << endl;
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            break;

        case 7:
            cout << endl;
            printList(p, count);///debugging and status info
            cout << "Count: "<< count << ". Size: " << size << "." << endl << endl;
            break;
        case 8:
            cout << "Goodbye." << endl;
            break;
        default:
            cout << "Invalid menu choice." << endl;
            break;
        }


    }
    while(choice != 8);

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
    cout << "1) Append a new element to the end of the list." << endl;
    cout << "2) Insert a new element at the beginning of the list." << endl;
    cout << "3) Insert an element into the list at a given index." << endl;
    cout << "4) Remove an element from the list at a given index." << endl;
    cout << "5) Sort the list with selection sort." << endl;
    cout << "6) Sort the list with quick sort." << endl;
    cout << "7) Print the contents of the list." << endl;
    cout << "8) Exit." << endl;
}

void printList(int *p, int count)
{
    cout << "Mem allocated: " << ALLOCATED << endl;
    cout << "Contents of the list: " << endl;
    for(int i = 0; i < count; i++)
    {
        cout << *(p + i) << " : ";
    }
    cout << endl;
}

int* expand(int *p, int &count, int &size)
{
    size++;
    count = size-1;
    ALLOCATED = count*sizeof(count);
    cout << "Expanding the list." << endl;
    int *temp = new int[size];

    for(int i = 0; i < count; i++)
    {
        *(temp + i) = *(p + i);
    }
    delete []p;
    return temp;
}
int* shrink(int *p, int &count, int &size)
{
    ///size *= 2;
    size--;
    count = size-1;
    ALLOCATED = count*sizeof(count);
    cout << "Shrinking the list. " << size << endl;
    int *temp = new int[count];

    for(int i = 0; i < count; i++)
    {
        *(temp + i) = *(p + i);
    }
    delete []p;
    return temp;
}

///I'm using slightly different names for my own convenience but the type and ordering still matches your spec
///from the callers perspective this is irrelevant
bool insert(int *p, int input, int index, int count)
{
    ///int *temp = 0;
    bool growFlag = false;
    ///check that the user has chosen a valid index
    ///pass back the input list this is also checked in main...
    if (index > (count-1)|| index < 0)
    {
        growFlag = false;
        ///temp = p;
    }
    else
    {
        ///int tempLast = *(p+count-1);///squirrel the last elem away temporarily
        ///shift the whole array to the right by one...
        for (int i = count-1; i >= index; i--)
        {
            *(p+i+1) = *(p+i);
        }
        ///*(p+count) = tempLast;    ///reset the last element
        *(p+index) = input;
        growFlag = true;
    }
    return growFlag;
};
///selection sort
void sort(int *p, int size)
{
    ///startScan, minIndex, minValue
    int sScan, minI, minV;
    for (int sScan = 0; sScan < (size - 1); sScan++)
    {
        minI = sScan;
        minV = *(p+sScan); ///p[sScan]
        for (int i = sScan + 1; i < size; i++)
        {
            if (*(p+i) < minV)
            {
                minV = *(p+i);
                minI = i;
            }
        }
        *(p+minI) = *(p+sScan);
        *(p+sScan) = minV;
    }
}

///I have never tried quick sort so I will try that
///your prototype will be a wrapper to a call to quicksort
///I don't quite understand the algorithm, it seems like it
///the array recursively and sorts the individual partitions...
void sortquick(int *p, int size)
{
    ///lo is 0 and high is the length of the array
    quickSort(p, 0, size);
}

void quickSort(int *p, int first, int last)
{
    int pivot = 0;
    if (first < last)
    {
        pivot = partition(p,first, last);
        quickSort(p,first,pivot-1);
        quickSort(p,pivot+1,last);
    }
}

int partition(int *p, int lo, int hi)
{
    ///setup like before
    int low = *(p+lo);
    int high = *(p+hi);

    int temp = 0;
    int pivot = *(p+lo);
    int leftWall = lo;
    for (int i = lo+1; i <= hi; i++)
    {
        if (p[i] < pivot)
        {
            ///inline swap because lazy..
            temp = *(p+i);
            *(p+i) = *(p+leftWall);
            *(p+leftWall) = temp;
            leftWall++;
            ///cout << "Here";
        }

    }
    ///one more inline swap because lazy
    temp = *(p+leftWall);
    *(p+leftWall) = pivot;
    pivot = temp;
    return leftWall;
}
bool remove(int *p, int index, int count)///int *p, int index, int count
{
    bool growFlag = false;
    ///check that the user has chosen a valid index
    ///pass back the input list this is also checked in main
    if (index > (count-1)|| index < 0)
    {
        growFlag = false;
    }
    ///int tempLast = *(p+count-1);///squirrel the last elem away temporarily
    ///shift the whole array to the left we basically want to "fold" on top of the users index
    ///for example for input index 3:
    ///before [0][1][2][3][4][5]
    ///after  [0][1][2][4][5][garbage]
    for (int i = index; i < count; i++)
    {
        *(p+i) = *(p+i+1);
    }

    growFlag = true;
    ///set the last element to something obviously garbage
    ///which we will deallocate soon...
    p[count-1] = -123456789;
    return growFlag;
}
