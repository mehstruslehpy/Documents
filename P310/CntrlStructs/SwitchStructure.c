#include <stdio.h>

int main()
{
	int x = 5;
	int y = 255;
	switch (x)
	{
		case 0:
		{
			y = 1;
			printf("y=1;\n");
			break;
		}
		case 1:
		{
			y = 2;
			printf("y=2;\n");
			break;
		}
		case 2:
		{
			y = 3;
			printf("y=3;\n");
			break;
		}
		case 3:
		{
			y = 4;
			printf("y=4;\n");
			break;
		}
		case 4:
		{
			y = 5;
			printf("y=5;\n");
			break;
		}
		default:
		{
			printf("y=255;\n");
			break;
		}
	}
	return 0;	
}
