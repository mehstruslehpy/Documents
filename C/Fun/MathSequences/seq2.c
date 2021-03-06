#include <stdio.h>
#include <math.h>

int main()
{
	//two long doubles for calculation 
	//n is the index 
	//a is a number generated by a recurrence relation
	//cont is used for user input
	long double a = 1; 
	long double n = 0;
	char cont = 'y';

	while (cont == 'y')
	{
		//generate and print the output
		for (int i = 0; i < 10; i++)
		{
			a =  (pow(-1,n) * n) / (pow(n,2) + 1);	
			n = n + 1;

			printf("n = %d\n", (long) n);
			printf("a_n = %.1000Lf\n\n", a);	//so many digits
		}										//is excessive
		printf("Continue(y/n):");
		
		//query user for more input
		cont = getchar();
		if (cont == '\n')
		{
			cont = getchar();
		}
	}
}
