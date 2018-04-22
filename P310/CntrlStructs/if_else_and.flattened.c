#include <stdio.h>

int main()
{
	int a = 0;
	int b = -1;
	int c = 7;

	//if (b<=1 && c!=a)
	if (1 < b) goto ELSE;
	if (c<a) goto IF;
	if (a<c) goto IF;
	goto ELSE;
	IF:
		printf("case 1: a = 99\n");
		a = 99;
		goto ENDIF;
	ELSE:
		printf("case 2: a = 15\n");
		a = 15;
	ENDIF:
	return 0;
}
