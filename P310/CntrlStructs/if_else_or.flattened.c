#include <stdio.h>

int main()
{
	int a = 77;
	int b = 5;
	int c = 23;

	//if (b>=1 || c==a)
	if (1<b) goto IF;
	if (b==1) goto IF;
	if (c==a) goto IF;
	goto ELSE;
	IF:
		printf("case 1: a = 99\n");
		a = 99;
		goto END;
	ELSE:
		printf("case 2: a = 15\n");
		a = 15;
	END:
	return 0;
}
