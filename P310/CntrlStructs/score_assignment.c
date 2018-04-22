/*
**	Score Assignment: This is a simple programming
**	Exercise that I will translate to C from a given
**	PseudoCode then I will translate it to ttpasm
*/

#include <stdio.h>

int main()
{
    int score = 75;

	printf("Your grade is: ");
    if (score < 60)
    {
        printf("F");	//ascii 70
    }
    else if (score < 70)
    {
        printf("D");	//ascii 68
    }
    else if (score < 80)
    {
        printf("C");	//ascii 67
    }
    else if (score < 90)
    {
        printf("B");	//ascii 66
    }
    else
    {
        printf("A");	//ascii 65
    }
	printf("\n");
}
