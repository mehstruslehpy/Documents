#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

const int SIZE = 20;

void showArray(string[], int[], int);
void insertionSort(string[], int[], int);
int binSearch(string[], string, int);

int main()
{
	string user;
	int found = -1;

string name[SIZE] =
{"Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
"Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
"Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
"Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
"Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth"};

int money[SIZE] =
{500, 10000, 15000, 150,
1, 10, 25000, 9999,
1100, 500, 700, 800,
2000, 50000, 400, 200,
500, 700, 2200, 6500};


    showArray(name, money,SIZE);
    insertionSort(name, money,SIZE);
    showArray(name, money, SIZE);
	do
	{
		found = -1;
		cout << "Enter a name to search: " << endl;
		getline(cin, user);
		if (((found = binSearch(name, user, SIZE)) != -1) && found >= 0 && found <= SIZE-1)
		{
			cout << "MATCH AT INDEX: " << found << endl;
			cout << name[found] << " owes $" << money[found] << endl;
		}
		else
		{
			cout << "NO MATCH!" << endl;
		}
	
	} while(user != "QUIT" && user != "quit");

    return 0;
}

void showArray(string a[], int m[], int size)
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
        cout << i << ": " << a[i] << " " << m[i] << endl;
    }
    sorted = true;
    cout << endl;
}
void insertionSort(string a[], int m[], int size)
{
    int j;
	int temp2;
	string temp1;
	int comparisons = 0, swaps = 0;

	for (int i = 1; i < size; i++)
    {
		j = i;

		while (j > 0 && a[j] < a[j-1])
        {		
				///swap the names
			  temp1 = a[j];
			  a[j] = a[j-1];
			  a[j-1] = temp1;
				///swap the money
			  temp2 = m[j];
			  m[j] = m[j-1];
			  m[j-1] = temp2;

			  j--;
			  comparisons++; swaps++;
        }
	}
    cout << "The number of comparisons from insertion sort: " << comparisons << endl;
    cout << "The number of swaps from insertion sort: " << swaps << endl;
}

///I commented out a portion of this in a previous version that matched partial names
///but it had too many bugs, and returned too many false positives so I scrapped it.
int binSearch(string arr[], string name, int size)
{
	int first = 0;
	int last = size; 
	bool found = false;
	int position = -1;
	while (!found && first <= last)
	{
		int middle = (first + last) / 2;
		//if (arr[middle] == name || arr[middle].find(name) != string::npos)
		if (arr[middle] == name)
		{
			found = true;
			position = middle;
		}
		else if (arr[middle] > name)
		{
			last = middle - 1;
		}
		else 
		{
			first = middle + 1;
		}
	}
	return position;
}
