/************************
Author: Mehstruslehpy
Date:	24 Dec 2017
************************/

#include "CArray.h"

using namespace std;

//functions to run my tests and print any exceptions
int arr_printError(int);
int arr_ctorTest();
int arr_printTest();
int arr_opEqualTest();
int arr_opBracketTest();
int arr_appendTest();
int arr_subArrTest();
int arr_addTest();
int arr_removeTest();
int arr_fileIOTest();

int ArrayTests()
{
    cout << "Beginning tests...\n";
    try
    {
        arr_ctorTest();
        arr_printTest();
        arr_opEqualTest();
        arr_opBracketTest();
        arr_appendTest();
        arr_subArrTest();
        arr_addTest();
        arr_removeTest();
        arr_fileIOTest();
        cout << "Testing complete.\n";
    }
    catch (int a)
    {
        cout << endl << endl;
        cout << "Caught exception: ";
        cout << a << endl;
        cout << "Exception location: ";
        arr_printError(a);
    }
    return 0;
}

int arr_ctorTest()
{
    cout << "Testing constructors...\n";
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,4,123};

    CArray<int> test1(a,16);
    CArray<int> test2(b,4,-3);
    CArray<int> test3(-7);
    CArray<int> test4;
    return 0;
}

int arr_printTest()
{
    cout << "Testing printing...\n";
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,4,123};

    CArray<int> test1(a,16);
    CArray<int> test2(b,4,-3);
    CArray<int> test3(a,7,-7);
    CArray<int> test4(test2);

    cout << "\ttest1: "<< test1 << endl;
    cout << "\ttest2: "<< test2 << endl;
    cout << "\ttest3: "<< test3 << endl;
    cout << "\ttest4: "<< test4 << endl;
    return 0;
}

int arr_opEqualTest()
{
    cout << "Testing operator=...\n";
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    CArray<int> test1(a,16);
    CArray<int> test4(c,13,-7);
    CArray<int> *rptr;

    rptr = &test4;
    cout << "\t*rptr = test4: " << rptr << endl;
    cout << "\ttest1=test2=test3=test4:\n\t" << (test4=test1=*rptr) << endl;
    cout << "\ttest4:" << (test4) << endl;
    return 0;
}

int arr_opBracketTest()
{
    cout << "Testing operator[]...\n";
    int SIZE = 13;
    int VINDEX = -4;
    int SIZE_1 = 15;
    int VINDEX_1 = -444;

    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    CArray<int> test1(a,16);
    CArray<int> test5(c,SIZE,VINDEX);
    const CArray<int> ctest(a,SIZE_1,VINDEX_1);

    cout << "\ttest5(loop): ";
    for (int i = VINDEX; i < SIZE+VINDEX; ++i)
    {
        cout << test5[i] << "  ";
    }
    cout << endl;
    cout <<"\ttest5: " << test5 << endl;

    cout << "\tctest(loop): ";
    for (int i = VINDEX_1; i < SIZE_1+VINDEX_1; ++i)
    {
        cout << ctest[i] << "  ";
    }
    cout << endl;
    cout << "\tctest: " << ctest << endl;
    return 0;
}

int arr_appendTest()
{
    cout << "Testing append..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,4,123};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};
    int d[] = {1,0,-1,1,-0,1,-2};

    CArray<int> test1(a,16);
    CArray<int> test2(b,4,-3);
    CArray<int> test7(c,8,-44);
    CArray<int> test8(d,7,3);
    CArray<int> test9(c,3,-17);

    cout << "\ttest8(before): "<< test8 << endl;
    test8.append(test8);    //append to self
    cout << "\ttest8(after): "<< test8<< endl;
    cout << "\ttest7(before): "<< test7<< endl;
    test7.append(test1(5,8)); // pos rub to neg rub also append a sub rub
    cout << "\ttest7(after): "<< test7<< endl;
    test1 = test2(-2,0); //this is a good test and will make printing easier
    cout << "\ttest1(before): "<< test1<< endl;
    test1.append(test7);    //append a neg rub to a pos rub
    cout << "\ttest1(after): "<< test1<< endl;
    cout << "\ttest9(before): "<< test9<< endl;
    for (int i = 0; i < 5; ++i)
    {
        test9.append(i);
    }
    cout << "\ttest9(before): "<< test9 << endl;
    return 0;
}

int arr_subArrTest()
{
    cout << "Testing operator()..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    CArray<int> test1(a,16);
    CArray<int> test7(c,8,-44);

    cout << "\ttest1(3,7): " << test1(3,7);
    cout << "\n\ttest7:" << test7;
    cout << "\n\ttest7(-43,-38): " << test7(-43,-38);
    cout << "\n\ttest1(7,15): " << test1(7,15) << endl;
    cout << "\ttest1(0,3): " << test1(0,3) << endl;
    cout << "\ttest7(all): " << test7 << endl;
    cout << "\ttest7(-40,-37): " << test7(-40,-37) << endl;
    return 0;
}
int arr_addTest()
{
    cout << "Testing add..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    int VINDEX = -4;
    int SIZE = 7;

    CArray<int> test1(a,16);
    CArray<int> test5(c,SIZE,VINDEX);

    test5.remove();
    test5.remove();
    cout << "\ttest5(before): " << test5 << endl;
    for (int i = 0; i < 2; ++i)
    {
        test5.add(3+i+VINDEX,i);
    }
    cout << "\ttest5(after): " << test5 << endl;
    cout << "\ttest5(before): " << test5 << endl;
    test5.add(-1,234);
    test1.add(3,-55);
    cout << "\ttest5(after): " << test5 << endl;

    test1.remove();
    test1.remove();
    test1.remove();
    cout << "\ttest1(before): " << test1 << endl;
    for (int i = 5; i < 7; ++i)
    {
        test1.add(i);
    }
    cout << "\ttest1(after): " << test1 << endl;;
    return 0;
}
int arr_removeTest()
{
    cout << "Testing remove..." << endl;

    int SIZE = 8;
    int VINDEX = -4;

    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,-4,123,98,-12,333,1919};

    CArray<int> test1(a,16);
    CArray<int> test5(b,SIZE,VINDEX);

    cout << "\ttest5(before): " << test5 << endl; //single elem default remove with vindex of -4
    test5.remove();
    test5.remove();
    cout << "\ttest5(after): " << test5 << endl;
    cout << "\ttest5(before): " << test5 << endl; //single elem remove with vindex of -4 and specified index of -2
    test5.remove(-2);
    test5.remove(-2);
    test5.remove(-4);
    cout << "\ttest5(after): " << test5 << endl;
    cout << "\ttest1(before): " << test1 << endl; //single elem default remove
    test1.remove();
    test1.remove();
    cout << "\ttest1(after): " << test1 << endl;
    cout << "\ttest1(before): " << test1 << endl; //single elem remove with specified index of 2
    test1.remove(2);
    test1.remove(2);
    test1.remove(10);
    cout << "\ttest1(after): " << test1 << endl;
    cout << "\ttest1(before): " << test1 << endl; //ranged remove
    test1.remove(2,5); //2 to 4 will be removed
    cout << "\ttest1(after): " << test1 << endl;
    test5.append(test5);
    test5.append(test5);
    cout << "\ttest5(before): " << test5 << endl; //ranged remove
    test5.remove(-3,4); //-4 to 3 will be removed
    cout << "\ttest5(after): " << test5 << endl;
    return 0;
}
int arr_fileIOTest()
{
    cout << "Testing file IO..." << endl;
    int MAX_SIZE = 9;
    int V_INDEX = -2;
    char ca[] = { 'D','E','A','D','_','B','E','E','F'};
    ofstream fout("ArrayTest.txt", ios::out | ios::binary | ios::trunc);
    //string mystr = "HEYDUDEWHATSUP!";
    CArray<char> write_ra(ca,MAX_SIZE,V_INDEX);
    //CArray<char> write_ra(mystr.c_str(),mystr.length()+1,-5);
    CArray<char> read_ra;

    write_ra.write(fout);
    cout << "\twrite_ra: " << write_ra << endl;
    fout.close();
    ifstream fin("ArrayTest.txt", ios::in | ios::binary);
    read_ra.read(fin);
    cout << "\tread_ra:  " << read_ra << endl;

    fout.close();
    fin.close();
    return 0;
}

int arr_printError(int msg)
{
    switch (msg)
    {
    case 1:
        cout << "T& CArray<T>::operator[] ( int Vindex )" << endl;
        break;
    case 2:
        cout << "const T& CArray<T>::operator[] ( int Vindex ) const" << endl;
        break;
    case 3:
        cout << "CArray<T> CArray<T>::operator( ) ( int Vfirst, int Vlast ) const" << endl;
        break;
    case 4:
        cout << "void CArray<T>::add ( int Vindex, const T& rt)" << endl;
        break;
    case 5:
        cout << "void CArray<T>::remove ( int Vindex )" << endl;
        break;
    case 6:
        cout << "void CArray<T>::remove ( int Vfirst, int Vlast )" << endl;
        break;
    default:
        cout << "Unknown" << endl;
    }
    return 0;
}
