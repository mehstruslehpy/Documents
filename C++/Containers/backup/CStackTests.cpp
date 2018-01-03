/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#include "CStack.h"

using namespace std;

int cstk_printError(int);
int cstk_ctorTests();
int cstk_opEqualTests();
int cstk_printTests();
int cstk_pushPopPeekTests();
int cstk_Auxiliary();
int cstk_fileIOTests();
int cstk_subArrAndSubStkTests();
int cstk_advancedOps();

int CStackTests()
{
    cout << "Beginning cstack tests...\n";
    try
    {
        cstk_ctorTests();
        cstk_opEqualTests();
        cstk_printTests();
        cstk_pushPopPeekTests();
        cstk_Auxiliary();
        cstk_fileIOTests();
        cstk_subArrAndSubStkTests();
        cstk_advancedOps();
        cout << "Testing complete.\n";
    }
    catch (int a)
    {
        cout << endl << endl;
        cout << "Caught exception in local CArray<T>: \n";
        cout << a << endl;
        cout << "Exception location: ";
        cstk_printError(a);
    }
    return 0;
}
int cstk_ctorTests()
{
    cout << "Testing constructors..." << endl;
    int arr[] = {1,2,3,4,5};
    int arr2[] = {3,6,9,12,15,18};
    CArray<int> rub(arr2,6);
    CStack<int> stk1;
    stk1.push(2);
    stk1.push(4);
    stk1.push(6);
    stk1.push(8);
    stk1.push(10);

    CStack<int> stk2(stk1);
    CStack<int> stk3(arr,5);
    CStack<int> stk4(rub);

    cout << "\tstk1:  " << stk1 << endl;
    cout << "\tstk2(stk1): " << stk2 << endl;
    cout << "\tstk3(arr): " << stk3 << endl;
    cout << "\tstk4(rub): " << stk4 << endl;
    return 0;
}
int cstk_opEqualTests()
{
    cout << "Testing operator=()..." << endl;
    int arr2[] = {3,6,9,12,15,18};
    CArray<int> rub(arr2,6);
    cout << "rub(pre):  " << rub << endl;
    CStack<int> stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    cout << "\tstk1(pre):  " << stk1 << endl;
    CStack<int> stk2(rub);
    stk2.pop();
    stk2.pop();
    CStack<int> stk3(stk1);
    cout << "\tstk2(pre):  " << stk2 << endl;
    cout << "\tstk3(pre):  " << stk3 << endl;
    cout << "\tstk1=stk2:  " << (stk1=stk2) << endl;
    cout << "\tstk2=rub: " << (stk2=rub) << endl;
    cout << "\tstk3=stk3: " << (stk3=stk3) << endl;
    cout << "\tstk2=rub: " << (stk2=rub) << endl;
    cout << "\tstk2=stk1: " << (stk2=stk1) << endl;
    return 0;
}
int cstk_printTests()
{
    cout << "Testing printing..." << endl;
    int arr[] = {3,6,9,12,15,18};
    CStack<int> stk1(arr,6);
    CStack<int>* stk2 = new CStack<int>(arr,3);
    cout << "\tstk1: " << stk1 << endl;
    cout << "\t*stk2: " << stk2 << endl;
    delete stk2;
    return 0;
}

int cstk_pushPopPeekTests()
{
    cout << "Testing push pop and peek..." << endl;
    int arr[] = {3,6,9,12,15,18,21,24,27,30};
    CArray<int> ra(arr,5);
    CStack<int> stk1(arr,3);
    CStack<int> stk2(arr,6);
    CStack<int> stk3;
    stk3.push(stk1);
    CStack<int> stk4;
    stk4.push(2);
    stk4.push(4);
    stk4.push(6);
    stk4.push(8);
    stk4.push(arr,3);

    cout << "\tstk1: " << stk1 << endl;
    cout << "\tstk2: " << stk2 << endl;
    cout << "\tstk3: " << stk3 << endl;
    cout << "\tstk4: " << stk4 << endl;
    cout << "\tstk1.pop(): " << stk1.pop() << " " << stk1.pop() << " " << stk1.pop() << " " << endl;
    cout << "\tstk1: " << stk1 << endl;

    stk1.push(1);
    cout << "\tstk1.push(1); stk1.peek(): " << stk1.peek() << endl;
    cout << "\tstk2.peek(3): " << stk2.peek(3) << endl;
    cout << "\tstk3.peek(2): " << stk3.peek(2) << endl;
    cout << "\tstk4.peek(5): " << stk4.peek(5) << endl;
    stk3.push(stk3);
    cout << "\tstk3.push(stk3): " << stk3 << endl;
    return 0;
}
int cstk_Auxiliary()
{
    cout << "Testing auxiliaries..." << endl;
    int arr[] = {3,6,9,12,15,18,21,24,27,30};
    CArray<int> ra(arr,5);
    CStack<int> stk1(arr,3);
    CStack<int> stk2(arr,6);
    CStack<int> stk3;
    CStack<int> stk4;
    stk4.push(2);
    stk4.push(4);
    stk4.push(6);
    stk4.push(8);
    stk4.push(arr,3);
    cout << "\tstk1: " << stk1 << endl;
    cout << "\tstk1.length():" << stk1.length() << ":stk1.isEmpty():" << stk1.isEmpty() << endl;
    cout << "\tstk2: " << stk2 << endl;
    cout << "\tstk2.length():" << stk2.length() << ":stk2.isEmpty():" << stk2.isEmpty() << endl;
    cout << "\tstk3: " << stk3 << endl;
    cout << "\tstk3.length():" << stk3.length() << ":stk3.isEmpty():" << stk3.isEmpty() << endl;
    cout << "\tstk4: " << stk4 << endl;
    cout << "\tstk4.length():" << stk3.length() << ":stk4.isEmpty():" << stk4.isEmpty() << endl;
    return 0;
}
int cstk_fileIOTests()
{
    cout << "Testing file IO..." << endl;
    int MAX_SIZE = 19;
    char ca[] = { 'D','E','A','D','_','B','E','E','F','_','B','E','E','F','_','D','E','A','D'};
    ofstream fout("CStackTest.txt", ios::out | ios::binary | ios::trunc);
    CStack<char> write_stk(ca,MAX_SIZE);
    CStack<char> read_stk;

    write_stk.write(fout);
    cout << "\twrite_stk: " << write_stk << endl;
    fout.close();
    ifstream fin("CStackTest.txt", ios::in | ios::binary);
    read_stk.read(fin);
    cout << "\tread_stk:  " << read_stk << endl;

    fout.close();
    fin.close();
    return 0;
}

int cstk_subArrAndSubStkTests()
{
    cout << "Testing subarray and substack functions..." << endl;
    int intarr[] = {31,13,29,99,50,81891,85,2};
    CStack<char> stk1("Hello, my name is tom",22);
    CStack<int> stk2(intarr,8);
    cout << "\tstk1: "<< stk1 << endl;
    cout << "\tstk2: "<< stk2 << endl;

    cout << "\tstk1.subCStack(18,21): "<< stk1.subCStack(18,21) << endl;
    cout << "\tstk2.subArray(3,6): " << stk2.subArray(3,6) << endl;
    cout << "\tstk1.subCStack(3,5).isEmpty(): " << stk1.subCStack(3,5).isEmpty() << endl;
    cout << "\tstk2.subArray(3,5).length(): " << stk1.subCStack(3,5).length() << endl;
    return 0;
}
int cstk_advancedOps()
{
    cout << "CStack advanced operations tests..." << endl;
    CStack<int> stk;

    for (int i =0; i < 10; ++i)
    {
        stk.push(i);
    }
    cout << "\tstk(start): " << stk << endl;
    stk.dupl();
    cout <<"\tstk.dupl(): "<< stk << endl;
    stk.dupl();
    cout <<"\tstk.dupl(): "<< stk << endl;
    stk.pop();
    stk.pop();
    cout <<"\tstk.pop();stk.pop(): "<< stk << endl;

    stk.rrot();
    cout <<"\tstk.rrot(): "<< stk << endl;
    stk.rrot();
    cout <<"\tstk.rrot(): "<< stk << endl;
    stk.rrot();
    cout <<"\tstk.rrot(): "<< stk << endl;
    stk.rrot();
    cout <<"\tstk.rrot(): "<< stk << endl;

    stk.lrot();
    cout <<"\tstk.lrot(): "<< stk << endl;
    stk.lrot();
    cout <<"\tstk.lrot(): "<< stk << endl;
    stk.lrot();
    cout <<"\tstk.lrot(): "<< stk << endl;
    stk.lrot();
    cout <<"\tstk.lrot(): "<< stk << endl;

    stk.swap();
    cout << "\tstk.swap(): " << stk << endl;
    stk.swap();
    cout << "\tstk.swap(): " << stk << endl;

    stk.rrot(3);
    cout <<"\tstk.rrot(3): "<< stk << endl;
    stk.rrot(3);
    cout <<"\tstk.rrot(3): "<< stk << endl;
    stk.rrot(3);
    cout <<"\tstk.rrot(3): "<< stk << endl;

    stk.lrot(3);
    cout <<"\tstk.lrot(3): "<< stk << endl;
    stk.lrot(3);
    cout <<"\tstk.lrot(3): "<< stk << endl;
    stk.lrot(3);
    cout <<"\tstk.lrot(3): "<< stk << endl;

    stk.lrot(stk.size()-1);
    cout << "\tstk.lrot(stk.size()-1): " << stk << endl;
    stk.rrot(stk.size()-1);
    cout << "\tstk.rrot(stk.size()-1): " << stk << endl;

    stk.lrot(stk.size()-3);
    cout << "\tstk.lrot(stk.size()-3): " << stk << endl;
    stk.rrot(stk.size()-3);
    cout << "\tstk.rrot(stk.size()-3): " << stk << endl;

    stk.lrot(stk.size()-7);
    cout << "\tstk.lrot(stk.size()-7): " << stk << endl;
    stk.lrot(stk.size()-7);
    cout << "\tstk.lrot(stk.size()-7): " << stk << endl;
    stk.lrot(stk.size()-7);
    cout << "\tstk.lrot(stk.size()-7): " << stk << endl;
    stk.rrot(stk.size()-7);
    cout << "\tstk.rrot(stk.size()-7): " << stk << endl;
    stk.rrot(stk.size()-7);
    cout << "\tstk.rrot(stk.size()-7): " << stk << endl;
    stk.rrot(stk.size()-7);
    cout << "\tstk.rrot(stk.size()-7): " << stk << endl;


    return 0;
}

int cstk_printError(int msg)
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
