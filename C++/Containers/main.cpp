/************************
Author: Mehstruslehpy
Date:   24 Dec 2017
************************/

#include "CArrayTests.h"
#include "CStackTests.h"
#include "LStackTests.h"
#include "CListTests.h"
#include "LListTests.h"
#include <iostream>

using namespace std;

int main()
{
    ArrayTests();
    cout << endl;
    CStackTests();
    cout << endl;
    LStackTests();
    cout << endl;
    CListTests();
    cout << endl;
    LListTests();
    return 0;
}

