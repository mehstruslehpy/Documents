/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#include "CList.h"

using namespace std;

int clst_printError(int);
int clst_ctorTests();
int clst_opEqualTests();
int clst_printTests();
int clst_fileIOTests();
int clst_subArrAndSubLstTests();
int clst_newStuffTests();
int CListTests()
{
    cout << "Beginning clist tests...\n";
    try
    {
        clst_ctorTests();
        clst_opEqualTests();
        clst_printTests();
        clst_fileIOTests();
        clst_subArrAndSubLstTests();
        clst_newStuffTests();
        cout << "Testing complete.\n";
    }
    catch (int a)
    {
        cout << endl << endl;
        cout << "Caught exception in local CArray<T>: \n";
        cout << a << endl;
        cout << "Exception location: ";
        clst_printError(a);
    }
    return 0;
}

int clst_ctorTests()
{
    cout << "Testing constructors... \n";
    int a[] = {1,32,54,66,90,13,17,19};
    CArray<int> rub;
    rub.append(2);
    rub.append(4);
    rub.append(8);
    rub.append(16);
    rub.append(32);
    rub.append(64);
    CList<int> lst1(a,5);
    CList<int> lst2(rub);
    CList<int> lst3(lst1);
    CList<int> lst4;

    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst2: " << lst2 << endl;
    cout << "\tlst3: " << lst3 << endl;
    cout << "\tlst4: " << lst4 << endl;
    return 0;
}

int clst_opEqualTests()
{
    cout << "Testing operator=()..." << endl;
    int a[] = {1,3,7,13,17,19,23,29};
    CArray<int> rub;
    rub.append(3);
    rub.append(6);
    rub.append(9);
    rub.append(12);
    rub.append(15);
    rub.append(18);
    CList<int> lst1(a,5);
    CList<int> lst2;
    CList<int> lst3(lst1);
    CList<int> lst4;

    cout << "\tlst1=rub: " << (lst1=rub) << endl;
    cout << "\tlst2=lst3: "<< (lst2=lst3) << endl;
    cout << "\tlst3=lst3: " << (lst3=lst3) << endl;
    cout << "\tlst4=lst3=lst2=lst1=rub: " << (lst4=lst3=lst2=lst1=rub) << endl;
    cout << "\trub:  " << rub << endl;
    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst2: " << lst2 << endl;
    cout << "\tlst3: " << lst3 << endl;
    cout << "\tlst4: " << lst4 << endl;
    return 0;
}

int clst_printTests()
{
    cout << "Testing printing..." << endl;
    int a[] = {1,3,7,13,17,19,23,29};
    int b[] = {2,4,6,8,10,12,14,16};
    int c[] = {3,6,9,12,15,18,21,24};
    int d[] = {4,8,12,16,20};
    int e[] = {3,33,333,3333};
    CList<int> lst1(a,3);
    const CList<int> lst2(b,5);
    CList<int>* lst3 = new CList<int>(c,7);
    const CList<int>* const lst4 = new CList<int>(d,2);
    CList<int>* const lst5 = new CList<int>(e,3);
    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst2: " << lst2 << endl;
    cout << "\tlst3: " << lst3 << endl;
    cout << "\tlst4: " << lst4 << endl;
    cout << "\tlst5: " << lst5 << endl;
    delete lst3;
    delete lst4;
    delete lst5;
    return 0;
}

int clst_fileIOTests()
{
    cout << "Testing file IO..." << endl;
    int MAX_SIZE = 16;
    ofstream fout("CListTest.txt", ios::out | ios::binary | ios::trunc);
    CList<char> write_lst("Hello, my dude!",MAX_SIZE);
    CList<char> read_lst;

    write_lst.write(fout);
    cout << "\twrite_lst: " << write_lst << endl;
    fout.close();
    ifstream fin("CListTest.txt", ios::in | ios::binary);
    read_lst.read(fin);
    cout << "\tread_lst:  " << read_lst << endl;

    fout.close();
    fin.close();
    return 0;
}

int clst_subArrAndSubLstTests()
{
    cout << "Testing subarray and subclist functions..." << endl;
    CArray<char> rub;
    CList<char> lst1("What up bro?",13);
    CList<char> lst2("Hey dude how are you?",22);

    cout << "\tlst1: " << lst1 << endl;
    cout << "\trub: " << rub << endl;
    cout << "\tlst2: " << lst2 << endl;

    cout << "\trub=lst1.subArray(): " << (rub=lst1.subArray(0,4)) << endl;
    cout << "\tlst2=lst1.subList(): " << (lst2=lst1.subList(5,12)) << endl;

    return 0;
}
int clst_newStuffTests()
{
    cout << "Testing new stuff...\n";
    int a[] = {1,3,7,13,17,19,23,29};
    CArray<int> rub;
    rub.append(3);
    rub.append(6);
    rub.append(9);
    rub.append(12);
    rub.append(15);
    rub.append(18);
    CList<int> lst1(a,5);
    CList<char> lst2("Hey dude how are you doing?",28);

    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst1.tail(): " << lst1.tail() << endl;
    cout << "\tlst1.head(): " << lst1.head() << endl;
    cout << "\tlst1.tail().isEmpty(): " << lst1.tail().isEmpty() << endl;
    cout << "\tlst1.tail().subArray(1,3): " << lst1.tail().subArray(1,3) << endl;
    cout << "\tlst1.tail().tail(): " << lst1.tail().tail() << endl;
    lst1.insert(2,1337);
    cout << "\tlst1.insert(2,1337): " << lst1 << endl;
    lst1.insert(1337);
    cout << "\tlst1.insert(1337): " << lst1 << endl;
    lst1.append(222333);
    cout << "\tlst1.append(222333): " << lst1 << endl;
    cout << "\tlst1.tail().tail().subList(1,5).tail(): " << lst1.tail().tail().subList(1,5).tail() << endl;
    cout << "\tlst1.tail().tail().subList(1,5).tail().contains(222333): " << lst1.tail().tail().subList(1,5).tail().contains(222333) << endl;
    cout << "\tlst1.tail().tail().subList(1,5).tail().contains(7): " << lst1.tail().tail().subList(1,5).tail().contains(7) << endl;
    cout << "\tlst1.tail().tail(): " << lst1.tail().tail() << endl;
    cout << "\tlst1.tail().tail().head(): " << lst1.tail().tail().head() << endl;
    lst1.remove();
    cout << "\tlst1.remove(): " << lst1 << endl;
    lst1.remove(2);
    cout << "\tlst1.remove(2): " << lst1 << endl;
    lst1.remove();
    cout << "\tlst1.remove(): " << lst1 << endl;
    lst1.append(lst1);
    cout << "\tlst1.append(lst1): " << lst1 << endl;
    lst1.remove();
    lst1.remove();
    lst1.remove();
    lst1.remove();
    lst1.remove();
    lst1.remove();
    lst1.remove();
    lst1.append(rub);
    cout << "\tlst1.append(rub): " << lst1 << endl;
    cout << "\tlst2: " << lst2 << endl;
    cout << "\tlst2.contains('i'): " << lst2.contains('i') << endl;
    cout << "\tlst2.contains('z'): " << lst2.contains('z') << endl;
    lst1.remove(1,4);
    cout << "\tlst1.remove(1,4): " << lst1 << endl;
    cout << "\tlst2.count('i'): " << lst2.count('i') << endl;
    cout << "\tlst2.count('z'): " << lst2.count('z') << endl;
    cout << "\tlst2.head().at(): " << lst2.head().at() << endl;
    cout << "\tlst2.tail().at(): " << lst2.tail().at() << endl;
    cout << "\tlst2.tail().at(1): " << lst2.tail().at(1) << endl;
    return 0;
}

int clst_printError(int msg)
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
