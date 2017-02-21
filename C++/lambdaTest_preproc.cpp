#include <iostream>

using namespace std;

void printFunction(int *);

int main()
{

    int arr[5] = {1,2,3,4,5};

    cout << "A perfectly normal call to a function:" << endl;
    printFunction([](int* lclArr) {
        cout << "SURPRISE LAMDA"<< endl;
        lclArr[0]=2;
        lclArr[1]=4;
        lclArr[2]=6;
        lclArr[3]=8;
        lclArr[4]=10;
        return lclArr;
    }(arr));

    cout << "Wait what just happened?\n...\nI better check and see if my array is still okay:"<< endl;
    printFunction(arr);

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
    return 0;
}

void printFunction(int *inArray)
{
    for(int i = 0; i < 5; i++)
        cout << inArray[i] << endl;

}
