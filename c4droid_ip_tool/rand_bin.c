#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {

    char a;
    time_t t;

    srand((unsigned) time(&t));
    for (int i = 0; i < 4; ++i) 
	{

        a = rand() % 26;

        while (a) 
		{
            if (a & 1)
                printf("1");
            else
                printf("0");

            a >>= 1;
        }

        if (i < 3) 
		{
            printf(".");
        }
        else 
		{
            printf(" \n");
        }
    }
}
