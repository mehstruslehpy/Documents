/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#include "LList.h"

using namespace std;

int llst_printError(int);
int llst_ctorTests();
int llst_fileIOTests();
int llst_opEqualTest();
int llst_opBracketTest();
int llst_appendTest();
int llst_subArrTest();
int llst_addTest();
int llst_removeTest();
int llst_atTest();
int llst_newStuffTest();

int llst_accessTest(); //test this more later

int LListTests()
{
    cout << "Beginning llist tests...\n";
    try
    {
        llst_ctorTests();
        llst_fileIOTests();
        llst_opEqualTest();
        llst_opBracketTest();
        llst_appendTest();
        llst_subArrTest();
        llst_addTest();
        llst_removeTest();
        llst_atTest();
        llst_accessTest();
        llst_newStuffTest();
        cout << "Testing complete.\n";
    }
    catch (int a)
    {
        cout << endl << endl;
        cout << "Caught exception in local LList<T>: \n";
        cout << a << endl;
        cout << "Exception location: ";
        llst_printError(a);
    }
    return 0;
}

int llst_ctorTests()
{
    cout << "Testing constructors... \n";
    int a[] = {1,2,3,4,5,6};
    LList<int> lst;
    LList<int> lst1(a,6);
    LList<int> lst2(lst);	//test with an empty lst this works and doesn't really hurt to allow
    LList<int> lst3(lst1(3,5)); //test with a partial list
    LList<int> lst4(a,1);	//test with a single int
    LList<int> lst5(a,0);	//test with an array of no ints
    //LList<int> lst6(NULL,5);	//test with an array of no ints this will segfault as expected

    cout << "\tlst:  " << lst << endl;
    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst2: " << lst2 << endl;
    cout << "\tlst3: " << lst3 << endl;
    cout << "\tlst4: " << lst4 << endl;
    cout << "\tlst5: " << lst5 << endl;
    //cout << "\tlst6: " << lst6 << endl;
    return 0;
}

int llst_fileIOTests()
{
    cout << "Testing file IO..." << endl;
    int MAX_SIZE = 19;
    ofstream fout("LListTest.txt", ios::out | ios::binary | ios::trunc);
    LList<char> write_lst("DOLLA DOLLA BILLS!",MAX_SIZE);
    LList<char> read_lst;

    write_lst.write(fout);
    cout << "\twrite_lst: " << write_lst << endl;
    fout.close();
    ifstream fin("LListTest.txt", ios::in | ios::binary);
    read_lst.read(fin);
    cout << "\tread_lst:  " << read_lst << endl;

    fout.close();
    fin.close();
    return 0;
}

int llst_opEqualTest()
{
    cout << "Testing operator=...\n";
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    LList<int> test1(a,16);
    LList<int> test4(c,13);
    LList<int> *rptr;

    rptr = &test4;
    cout << "\t*rptr = test4: " << rptr << endl;
    cout << "\ttest1=test2=test3=test4:\n\t" << (test4=test1=*rptr) << endl;
    cout << "\ttest4:" << (test4) << endl;

    //check that operator= actually copies
    /*
    for (int i = 0; i < test1.length(); i++)
    {
    	if (&test4[i] == &test1[i]) cout << "ADDRESS MATCH!" << endl;
    	cout << "\ttest4[" << i << "]: " << test4[i] <<" &test4[" << i << "]: " << &test4[i] << endl;
    	cout << "\ttest1[" << i << "]: " << test1[i] <<" &test1[" << i << "]: " << &test1[i] << endl;
    }
    */
    return 0;

}

int llst_opBracketTest()
{
    cout << "Testing operator[]...\n";
    int SIZE = 13;
    int SIZE_1 = 15;

    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    LList<int> test1(a,16);
    LList<int> test5(c,SIZE);
    const LList<int> ctest(a,SIZE_1);

    cout << "\ttest5(loop): ";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << test5[i] << "  ";
    }
    cout << endl;
    cout <<"\ttest5: " << test5 << endl;

    cout << "\tctest(loop): ";
    for (int i = 0; i < SIZE_1; ++i)
    {
        cout << ctest[i] << "  ";
    }
    cout << endl;
    cout << "\tctest: " << ctest << endl;
    return 0;

}

int llst_appendTest()
{
    cout << "Testing append..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,4,123};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};
    int d[] = {1,0,-1,1,-0,1,-2};

    LList<int> test1(a,16);
    LList<int> test2(b,4);
    LList<int> test7(c,8);
    LList<int> test8(d,7);
    LList<int> test9(c,3);

    cout << "\tPRECONDITION:" << endl;
    cout <<"\ttest1: " << test1 << endl;
    cout <<"\ttest2: " << test2 << endl;
    cout <<"\ttest7: " << test7 << endl;
    cout <<"\ttest8: " << test8 << endl;
    cout <<"\ttest9: " << test9 << endl;
    cout << "\tTESTING:" << endl;
    cout << "\ttest8(before): "<< test8 << endl;
    test8.append(test8);    //append to self
    cout << "\ttest8.append(test8): "<< test8<< endl;
    cout << "\ttest7(before): "<< test7<< endl;
    test7.append(test1(5,8));
    cout << "\ttest7.append(test1(5,8)): "<< test7<< endl;
    test1 = test2(0,2);
    cout  << "\ttest1 = test2(0,2): " << test1 << endl;
    cout << "\ttest1(before): "<< test1<< endl;
    test1.append(test7);
    cout << "\ttest1.append(test7): "<< test1<< endl;
    cout << "\ttest9(before): "<< test9<< endl;
    for (int i = 0; i < 5; ++i)
    {
        test9.append(i);
    }
    cout << "\ttest9(after): "<< test9 << endl;
    return 0;

}

int llst_subArrTest()
{
    cout << "Testing operator()..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    LList<int> test1(a,16);
    LList<int> test7(c,8);
    cout << "\tPRECONDITION: " << endl;
    cout <<"\ttest1: " << test1 << endl;
    cout <<"\ttest7: " << test7 << endl;
    cout << "\tTESTING:" << endl;
    cout << "\ttest1(3,7): " << test1(3,7);
    cout << "\n\ttest7:" << test7;
    cout << "\n\ttest7(5,7): " << test7(5,7);
    cout << "\n\ttest1(7,14): " << test1(7,14) << endl;
    cout << "\ttest1(0,3): " << test1(0,3) << endl;
    cout << "\ttest7(all): " << test7 << endl;
    cout << "\ttest7(3,7): " << test7(3,7) << endl;
    return 0;
}

int llst_addTest()
{
    cout << "Testing add..." << endl;
    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int c[] = {-8,15,1010,1337,98,5,1,3,378,276,32,54,14,10,99};

    int SIZE = 10;

    LList<int> test1(a,16);
    LList<int> test5(c,SIZE);

    test5.remove();
    test5.remove();
    cout << "\ttest5(before): " << test5 << endl;
    for (int i = 0; i < 2; ++i)
    {
        test5.add(3+i,i);
    }
    cout << "\ttest5(after): " << test5 << endl;
    cout << "\ttest5(before): " << test5 << endl;
    test5.add(1,234);
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

    //add off the end checks
}
int llst_removeTest()
{
    cout << "Testing remove..." << endl;

    int SIZE = 8;

    int a[] = {1,2,3,123,5,6,7,8,9,10,11,12,13,14,15,16};
    int b[] = {7,5,-4,123,98,-12,333,1919};

    LList<int> test1(a,16);
    LList<int> test5(b,SIZE);

    cout << "\ttest5(before): " << test5 << endl; //single elem default remove with vindex of -4
    test5.remove();
    test5.remove();
    cout << "\ttest5(after): " << test5 << endl;
    cout << "\ttest5(before): " << test5 << endl; //single elem remove with vindex of -4 and specified index of -
    test5.remove(2);
    test5.remove(2);
    test5.remove(3);
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
    test5.remove(3,5); //-4 to 3 will be removed
    cout << "\ttest5(after): " << test5 << endl;

    //add off the end checks
    return 0;

}
int llst_atTest()
{
    return 0;
}
int llst_newStuffTest()
{
    cout << "Testing new stuff...\n";
    int a[] = {1,3,7,13,17,19,23,29};
    LList<int> lrub;
    lrub.append(3);
    lrub.append(6);
    lrub.append(9);
    lrub.append(12);
    lrub.append(15);
    lrub.append(18);
    LList<int> lst1(a,5);
    LList<char> lst2("Hey dude how are you doing?",28);

    cout << "\tlst1: " << lst1 << endl;
    cout << "\tlst1.tail(): " << lst1.tail() << endl;
    cout << "\tlst1.head(): " << lst1.head() << endl;
    cout << "\tlst1.tail().isEmpty(): " << lst1.tail().isEmpty() << endl;
    cout << "\tlst1.tail().subArray(1,3): " << lst1.tail().subList(1,3) << endl;
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
    lst1.append(lrub);
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
int llst_accessTest()
{
    return 0;
}
int llst_printError(int msg)
{
    switch (msg)
    {
    case 1:
        cout << "T& LList<T>::operator[] ( int index ): index error" << endl;
        break;
    case 2:
        cout << "T& LList<T>::operator[] ( int index ): empty list" << endl;
        break;
    case 3:
        cout << "T LList<T>::at ( int index ) const: index error" << endl;
        break;
    case 4:
        cout << "T LList<T>::at ( int index ) const: empty list" << endl;
        break;
    case 5:
        cout << "const T& LList<T>::operator[] ( int index ) const: index error" << endl;
        break;
    case 6:
        cout << "const T& LList<T>::operator[] ( int index ) const: empty list" << endl;
        break;
    case 7:
        cout << "LList<T> LList<T>::operator( ) ( int first, int last ) const: index error" << endl;
        break;
    case 8:
        cout << "LList<T> LList<T>::operator( ) ( int first, int last ) const: empty list" << endl;
        break;
    case 9:
        cout << "void LList<T>::add ( int index, const T& rt): index error" << endl;
        break;
    case 10:
        cout << "void LList<T>::remove ( ): empty list" << endl;
        break;
    case 11:
        cout << "void LList<T>::remove ( int index ): empty list" << endl;
        break;
    case 12:
        cout << "void LList<T>::remove ( int index ): index error" << endl;
        break;
    case 13:
        cout << "void LList<T>::remove ( int first, int last ): empty list" << endl;
        break;
    case 14:
        cout << "void LList<T>::remove ( int first, int last ): index error" << endl;
        break;
    case 15:
        cout << "void LList<T>::write ( ofstream& outf )const: empty list" << endl;
    default:
        cout << "Unknown" << endl;
    }
    return 0;
}
