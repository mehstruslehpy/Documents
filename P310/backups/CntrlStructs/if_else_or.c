#include <stdio.h>

int main()
{
	int a = 77;
	int b = 5;
	int c = 23;

	if (b>=1 || c==a)
	{
		printf("case 1: a = 99\n");
		a = 99;
	}
	else
	{
		printf("case 2: a = 15\n");
		a = 15;
	}
}
