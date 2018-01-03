/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#include "LStack.h"

using namespace std;

int lstk_printError(int);
int lstk_ctorTests();
int lstk_opEqualTests();
int lstk_printTests();
int lstk_pushPopPeekTests();
int lstk_Auxiliary();
int lstk_fileIOTests();
int lstk_subArrAndSubStkTests();
int lstk_advancedOps();

int LStackTests()
{
    cout << "Beginning lstack tests...\n";
    try
    {
        lstk_ctorTests();
        lstk_opEqualTests();
        lstk_printTests();
        lstk_pushPopPeekTests();
        lstk_Auxiliary();
        lstk_fileIOTests();
        lstk_subArrAndSubStkTests();
        lstk_advancedOps();
        cout << "Testing complete.\n";
    }
    catch (int a)
    {
        cout << endl << endl;
        cout << "Caught exception in local LList<T>: \n";
        cout << a << endl;
        cout << "Exception location: ";
        lstk_printError(a);
    }
    return 0;
}
int lstk_ctorTests()
{
    cout << "Testing constructors..." << endl;
    int arr[] = {1,2,3,4,5};
    int arr2[] = {3,6,9,12,15,18};
    LList<int> rub(arr2,6);
    LStack<int> stk1;
    stk1.push(2);
    stk1.push(4);
    stk1.push(6);
    stk1.push(8);
    stk1.push(10);

    LStack<int> stk2(stk1);
    LStack<int> stk3(arr,5);
    LStack<int> stk4(rub);

    cout << "\tstk1:  " << stk1 << endl;
    cout << "\tstk2(stk1): " << stk2 << endl;
    cout << "\tstk3(arr): " << stk3 << endl;
    cout << "\tstk4(rub): " << stk4 << endl;
    return 0;
}
int lstk_opEqualTests()
{
    cout << "Testing operator=()..." << endl;
    int arr2[] = {3,6,9,12,15,18};
    LList<int> rub(arr2,6);
    cout << "rub(pre):  " << rub << endl;
    LStack<int> stk1;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    cout << "\tstk1(pre):  " << stk1 << endl;
    LStack<int> stk2(rub);
    stk2.pop();
    stk2.pop();
    LStack<int> stk3(stk1);
    cout << "\tstk2(pre):  " << stk2 << endl;
    cout << "\tstk3(pre):  " << stk3 << endl;
    cout << "\tstk1=stk2:  " << (stk1=stk2) << endl;
    cout << "\tstk2=rub: " << (stk2=rub) << endl;
    cout << "\tstk3=stk3: " << (stk3=stk3) << endl;
    cout << "\tstk2=rub: " << (stk2=rub) << endl;
    cout << "\tstk2=stk1: " << (stk2=stk1) << endl;
    return 0;
}
int lstk_printTests()
{
    cout << "Testing printing..." << endl;
    int arr[] = {3,6,9,12,15,18};
    LStack<int> stk1(arr,6);
    LStack<int>* stk2 = new LStack<int>(arr,3);
    cout << "\tstk1: " << stk1 << endl;
    cout << "\t*stk2: " << stk2 << endl;
    delete stk2;
    return 0;
}

int lstk_pushPopPeekTests()
{
    cout << "Testing push pop and peek..." << endl;
    int arr[] = {3,6,9,12,15,18,21,24,27,30};
    LList<int> ra(arr,5);
    LStack<int> stk1(arr,3);
    LStack<int> stk2(arr,6);
    LStack<int> stk3;
    stk3.push(stk1);
    LStack<int> stk4;
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
int lstk_Auxiliary()
{
    cout << "Testing auxiliaries..." << endl;
    int arr[] = {3,6,9,12,15,18,21,24,27,30};
    LList<int> ra(arr,5);
    LStack<int> stk1(arr,3);
    LStack<int> stk2(arr,6);
    LStack<int> stk3;
    LStack<int> stk4;
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
int lstk_fileIOTests()
{
    cout << "Testing file IO..." << endl;
    int MAX_SIZE = 19;
    char ca[] = { 'H','o','L','l','A','_','G','e','T','_','d','o','L','L','a','Z','Z','!','!'};
    ofstream fout("LStackTest.txt", ios::out | ios::binary | ios::trunc);
    LStack<char> write_stk(ca,MAX_SIZE);
    LStack<char> read_stk;

    write_stk.write(fout);
    cout << "\twrite_stk: " << write_stk << endl;
    fout.close();
    ifstream fin("LStackTest.txt", ios::in | ios::binary);
    read_stk.read(fin);
    cout << "\tread_stk:  " << read_stk << endl;

    fout.close();
    fin.close();
    return 0;
}

int lstk_subArrAndSubStkTests()
{
    cout << "Testing subarray and substack functions..." << endl;
    int intarr[] = {31,13,29,99,50,81891,85,2};
    LStack<char> stk1("Hello, my name is tom",22);
    LStack<int> stk2(intarr,8);
    cout << "\tstk1: "<< stk1 << endl;
    cout << "\tstk2: "<< stk2 << endl;

    cout << "\tstk1.subLStack(18,21): "<< stk1.subLStack(18,21) << endl;
    cout << "\tstk2.subArray(3,6): " << stk2.subArray(3,6) << endl;
    cout << "\tstk1.subLStack(3,5).isEmpty(): " << stk1.subLStack(3,5).isEmpty() << endl;
    cout << "\tstk2.subArray(3,5).length(): " << stk1.subLStack(3,5).length() << endl;
    return 0;
}
int lstk_advancedOps()
{
    cout << "Stack advanced operations tests..." << endl;
    LStack<int> stk;

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

int lstk_printError(int msg)
{
    switch (msg)
    {
    case 1:
        cout << "T& LList<T>::operator[] ( int Vindex )" << endl;
        break;
    case 2:
        cout << "const T& LList<T>::operator[] ( int Vindex ) const" << endl;
        break;
    case 3:
        cout << "LList<T> LList<T>::operator( ) ( int Vfirst, int Vlast ) const" << endl;
        break;
    case 4:
        cout << "void LList<T>::add ( int Vindex, const T& rt)" << endl;
        break;
    case 5:
        cout << "void LList<T>::remove ( int Vindex )" << endl;
        break;
    case 6:
        cout << "void LList<T>::remove ( int Vfirst, int Vlast )" << endl;
        break;
    default:
        cout << "Unknown" << endl;
    }
    return 0;
}
