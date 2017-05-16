#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstdlib>
#include "fish.h"

using namespace std;

class Player
{
private:
    Fish* inventory;
    int numFish;
    ///these private functions are used to implement merge-sort
    ///I modified the code from the entry for merge-sort on wikipedia
    ///my intention was to get a peek at an algorithm I had not tried before
    ///I don't feel like I learned a whole lot doing this this time
    void BottomUpMerge(Fish A[], int Left, int Right, int End, Fish B[]);
    void CopyArray(Fish B[], Fish A[], int n);
    void BottomUpMergeSort(Fish A[], Fish B[], int n);
    ///these private functions are used to determine if the array actually needs sorted
    ///from within sortInventory(), if isSorted() returns true then sortInventory skips
    ///trying to sort the array because it is already sorted.
    bool isSorted();
    void toggleSortFlag();
    bool sorted;
public:
    Player();
    ~Player();
    void goFish();
    void addFish(Fish fish);
    void getTotalScore();
    void printInventory();
    void sortInventory();
};

#endif // PLAYER_H
