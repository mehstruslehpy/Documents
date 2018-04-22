#include <stdio.h>

int main()
{
	int a = 0;
	int c = 22;
	int b = 12;
	
	BEGINWHILE1:
	if (c<a) goto ENDWHILE; 
	if (a<b) goto BEGINWHILE2;
	if (b<a) goto BEGINWHILE2;
	goto ENDWHILE;
	BEGINWHILE2:
		printf("a: %d\n",a);
		a++;
	goto BEGINWHILE1;
	ENDWHILE:
	
	printf("Done a: %d\n",a);
}
