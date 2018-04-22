#include <stdio.h>

int main()
{
	int x = 1;
	int y = 2;
	int z = 0;

	if (x > 0)
	{
		if (y <= z)
		{
			z = x;	
		}
		else
		{
			z = y;
		}
	}
	printf("Output: z=%d\n", z);
	
	return 0;
}
