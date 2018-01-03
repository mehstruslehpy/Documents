//
//	From 21st Century C pg 213
//
#include <stdio.h>
#define FPRINT(...) fprintf(stderr,__VA_ARGS__)
#define DBL_PRINT(human,machine) do {printf human; FPRINT machine;} while(0)

int main()
{
    int x = -1;
    if (x < 0) DBL_PRINT(("x is negative %g\n",x),("NEGVAL: x=%g\n",x));
}
