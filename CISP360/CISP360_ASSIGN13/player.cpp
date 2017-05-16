#include "player.h"

///a boring constructor
Player::Player()
{
    sorted = false;
    inventory = NULL;
    numFish = 0;
}
///a boring destructor
Player::~Player()
{
    delete [] inventory;
}
///determine the outcome of a fishing attempt
void Player::goFish()
{
    Fish common("common", 1);
    Fish medCommon("medium common",2);
    Fish medRare("medium rare", 3);
    Fish rare("rare",4);
    Fish ultraRare("ultra rare",5);

    int chance =  rand() % 3; ///chances from 0 to 3 so a 1 in 4 chance

    if (chance == 0)
    {
        toggleSortFlag();   ///if we are adding an entry to the structure then we are not sorted anymore
        chance = (rand() % 100) + 1;
        if (chance <= 60 && chance > 0)   ///1 to 60 is common
        {
            addFish(common);
        }
        else if (chance <= 80)   ///60-79 is medCommon
        {
            addFish(medCommon);
        }
        else if (chance <= 94)  ///80-93 is medRare
        {
            addFish(medRare);
        }
        else if (chance <= 99)   ///94-98 is rare
        {
            addFish(rare);
        }
        else if (chance == 100)   ///100 is ultraRare
        {
            addFish(ultraRare);
        }
        else
        {
            cout << "Error!" << endl;
        }

    }
}
///add a fish to the structure if luck sides with the user
void Player::addFish(Fish fish)
{
    ///allocate 1 + the prev num of fish
    Fish* tempFish = new Fish[numFish+1];

    for (int i = 0; i < numFish; i++)
    {
        tempFish[i].setName(inventory[i].getName().c_str());
        tempFish[i].setValue(inventory[i].getValue());
    }

    ///increment the amount of fish by one
    numFish++;

    ///free the old memory
    if (inventory != NULL)
    {
        delete [] inventory;
    }

    ///set the Fish* inventory to point to the new memory
    inventory = tempFish;

    ///assign values to the very last fish in the array
    tempFish[numFish-1].setName(fish.getName());
    tempFish[numFish-1].setValue(fish.getValue());
}

///sum and print the score
///this seems like it would be a good candidate for optimization
///similar to the sorting function
void Player::getTotalScore()
{
    int sum = 0;
    for (int i = 0; i < numFish; i++)
    {
        sum += inventory[i].getValue();
    }
    cout << "Total score: " << sum << endl;
}
///print each thing in the inventory array
void  Player::printInventory()
{
    for (int i = 0; i < numFish; i++)
    {
        cout << "Name for entry " << i << ": " << inventory[i].getName() << endl;
        cout << "Value for entry " << i << ": " << inventory[i].getValue() << endl;
    }
}
///if necessary sort everything
void Player::sortInventory()
{
    if (isSorted() != true)    ///if not already sorted
    {
        Fish* temp = new Fish[numFish];
        BottomUpMergeSort(inventory,temp,numFish);
        delete [] temp;
        toggleSortFlag();   ///we are now sorted so we can set this to true
    }
}
///merge sort stuff
///mostly adapted from wikipedia
void Player::BottomUpMergeSort(Fish A[], Fish B[], int n)
{
    for (int width = 1; width < n; width = 2 * width)
    {
        for (int i = 0; i < n; i = i + 2 * width)
        {
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        CopyArray(B, A, n);
    }
}
void Player::BottomUpMerge(Fish A[], int Left, int Right, int End, Fish B[])
{
    int i = Left;
    int j = Right;
    for (int k = Left; k < End; k++)
    {
        if (i < Right && (j >= End || A[i].getName() <= A[j].getName()))
        {
            B[k] = A[i];
            i = i + 1;
        }
        else
        {
            B[k] = A[j];
            j = j + 1;
        }
    }
}
void Player::CopyArray(Fish B[], Fish A[], int n)
{
    for(int i = 0; i < n; i++)
        A[i] = B[i];
}
///private member functions for determining if the array is sorted
///and changing the sorted flag status
bool Player::isSorted()
{
    return sorted;
}
void Player::toggleSortFlag()
{
    sorted = !sorted;
}
