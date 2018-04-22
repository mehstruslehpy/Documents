#include <stdio.h>

int main()
{
	int a = 0;
	int c = 22;
	int b = 12;
	while(!(a>c||a==b))
	{
		printf("a: %d\n",a);
		a++;
	}
	printf("Done a: %d\n",a);
}
