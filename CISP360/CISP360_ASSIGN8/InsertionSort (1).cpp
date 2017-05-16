#include <iostream>

using namespace std;

const int SIZE = 5;

void showArray(int[],int);
void insertionSort(int[],int);

int main()
{
    int a[] = {9,3,5,1,7};

    showArray(a,SIZE);
    insertionSort(a,SIZE);
    showArray(a,SIZE);
    return 0;
}

void showArray(int a[], int size)
{
    static bool sorted = false;
    if (sorted == false)
    {
        cout << "Pre sort:" << endl;
    }
    else
    {
        cout << "Post sort:" << endl;
    }
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << endl;
    }
    sorted = true;
    cout << endl;
}
void insertionSort(int a[], int size)
{
    int j, temp;
	int comparisons = 0, swaps = 0;

	for (int i = 1; i < size; i++)
    {

		j = i;
        cout << ".";
		while (j > 0 && a[j] < a[j-1])
        {
			  temp = a[j];
			  a[j] = a[j-1];
			  a[j-1] = temp;
			  j--;
			  comparisons++; swaps++;
			  cout << ".";
        }
	}
    cout << "The number of comparisons from insertion sort: " << comparisons << endl;
    cout << "The number of swaps from insertion sort: " << swaps << endl;
}
