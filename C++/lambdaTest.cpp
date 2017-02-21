#include <iostream>

//these will make sense later..
#define SURPRISE_TEXT cout << "SURPRISE LAMDA"<< endl
#define LAMBDA_ARG [](int* lclArr){SURPRISE_TEXT;lclArr[0]=2;lclArr[1]=4;lclArr[2]=6;lclArr[3]=8;lclArr[4]=10;return lclArr;}(arr)

using namespace std;

//our function to print our simple array
void printFunction(int *);

int main()
{
    //an array of 5 items 0-4
    int arr[5] = {1,2,3,4,5};

    //this is explained at the end of the file
    //basically it works like a normal function composition
    cout << "A perfectly normal call to a function:" << endl;
    printFunction(LAMBDA_ARG);

    //a generic function call
    cout << "Wait what just happened?\n...\nI better check and see if my array is still okay:"<< endl;
    printFunction(arr);

    //expressions can be validly passed, this is just a series of expressions evaluating to the final arr as far as I can tell?
    cout << "Well shoot that dang-ol lambda trickery broke my array! Maybe I can fix it in an equally obtuse manner:"<<endl;
    printFunction(
        (
            arr[0] = 1,
            arr[1] = 2,
            arr[2] = 3,
            arr[3] = 4,
            arr[4] = 5,
            arr
        ));

    //by the same logic I tried doing the exact same thing with statement blocks
    cout << "I wonder what else is legal C++ code:" << endl;
    printFunction(
        (
    {
        arr[0]=5*3;
        arr[1]=4*3;
        arr[2]=3*3;
        arr[3]=2*3;
        arr[4]=1*3;
        arr;
    }
        ));
}

void printFunction(int *inArray)
{
    for(int i = 0; i < 5; i++)
        cout << inArray[i] << endl;

}

//the basic idea of this code is that I defined LAMBDA_ARG as a shorthand for a lambda function that accepts an array
//which it will modify and return, this lambda is used as an argument to the printFunction function that I created
//this differs from actually declaring a function normally in that the lambda is expanded into the argument to printFunction
//during preprocessing before the program is compiled

//with the expression list what I think is happening is that everything between the parentheses is evaluated from left to right
//and the last evaluation: arr is the thing returned from the expression

//from what I gather the exact same thing is happening for the statement list as well? I am not exactly sure as I am not
//a C++ expert

// I might try and define and evaluate a function from within a statement block just to see if I can too.
