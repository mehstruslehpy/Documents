#include <stdio.h>
#include <stdlib.h>

///no namespace std in this case
//using namespace std;

void dollarFormat(char*,int);
///some quick helper functions
int lsearch(char*,const char, int);
void rshift(char*, int, int);

int main()
{
    ///a starting value for the size
    int size = 512;

    ///this is just stuff to allow the user to specify any length input
    ///but it is buggy, and I'm too lazy...
    ///It would be nice for this program to be able to read any length string
    /*
    char ignore;
    //string s;
    printf("Enter the maximum amount of characters your number will take: \n");
    scanf("%d",&size);
    scanf("%c",&ignore);
    */

    char* s = (char*) malloc(sizeof(int) * size);
    printf("Enter dollar amount in the form nnnn.nn :");
    scanf("%s",s);
    printf("Out: %s\n", s);
    dollarFormat(s,size);
    printf("Here is the amount formatted: \n");
    printf("Out: %s\n", s);

    free(s);
    return 0;
}

///your dollar format function but modified for cstrings
///and also for any length.. I don't recall if you did
///or did not originally have that because I keep changing
///this
void dollarFormat(char* currency, int length)
{
    int dp = lsearch(currency, '.', length);
    if(dp > 3)
    {
        for(int x = dp-3; x > 0; x-= 3)
        {
            rshift(currency,x,length);
            currency[x] =  ',';
        }
        rshift(currency,0,length);
        currency[0] = '$';
    }
}
///a linear search
int lsearch(char* input, const char a, int length)
{
    int index = -1;
    for (int i = 0; i < length; i++)
    {
        if(input[i] == a)
        {
            index = i;
        }
    }
    return index;
}

///a rightward shift of an array from the end to position n
///this is slow but can be optimized later
void rshift(char* input, int n, int length)
{
    for (int i = length; i > n; i--)
    {
        input[i] = input[i-1];
    }
}

