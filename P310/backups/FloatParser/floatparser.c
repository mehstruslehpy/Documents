#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 999
typedef int BOOL;
#define TRUE 1
#define FALSE 0

char* valstr(int argc, char** argv);	//validates user input
BOOL sign(char* str);					//retrieve whether or not the sign flag is set
double exponent(char* eloc);			//retrieve the value of the exponent part from the input
double mantissa(char* str, char* eloc); //retrieve the value of the mantissa part from the input
void adjust(double* mant, double* exp); //adjust the input to be representable as base-10 integers

int main(int argc, char** argv)
{
	char* eloc = NULL;	//location of 'e' or 'E' if it was input
	double exp = 0;		//exponent part
	double mant = 0;	//mantissa part
	BOOL bsign = FALSE; //sign bit part
	
	eloc = valstr(argc,argv);
	puts("String validation complete.");
	exp = exponent(eloc);
	mant = mantissa(argv[1],eloc);
	bsign = sign(argv[1]);

	puts("Your number:");
	printf("\tMantissa:  %f\n",mant);
	printf("\tExponent:  %f\n",exp);
	printf("\tSign-Flag: %s\n",(bsign)?("-"):("+"));
	
	adjust(&mant,&exp);
	
	//after adjust completes the input is expressible as an integer, 
	//casting allows for a cleaner display
	puts("Your number adjusted for conversion:");
	printf("\tMantissa:  %ld\n",(long)mant);
	printf("\tExponent:  %ld\n",(long)exp);
	printf("\tSign-Flag: %s\n",(bsign)?("-"):("+"));
	

	return EXIT_SUCCESS;

}

BOOL sign(char* str)
{
	return (str[0] == '-' )?(TRUE):(FALSE);
}

double exponent(char* eloc)
{
	return (eloc)?strtod((eloc+1),NULL):0;
}

double mantissa(char* str, char* eloc)
{
	double retval = 0;
	if(eloc)
	{
		str[eloc-str] = ' ';
		retval = strtod(str,NULL);
		str[eloc-str] = 'e';
	}
	else
	{
		retval = strtod(str,NULL);
	}
	return retval;
}

//adjust mantissa and exponent til mantissa is an integer
void adjust(double* mant, double* exp)
{
	char buffer1[MAX_LEN];
	char buffer2[MAX_LEN];
	
	//if the mantissa has a decimal portion casting it to a long
	//then back to a double will cause its string representation
	//to be truncated.

	//Any time this is the case the original string  representation 
	//and the the truncated string representation will be unequal

	snprintf(buffer1,MAX_LEN,"%f",*mant);
	snprintf(buffer2,MAX_LEN,"%f",(double)(long)*mant);
	while(strcmp(buffer1,buffer2))
	{
		(*mant) *= 10;
		(*exp)--;
		snprintf(buffer1,MAX_LEN,"%f",*mant);
		snprintf(buffer2,MAX_LEN,"%f",(double)(long)(*mant));
	}
}
//
//warnings can be changed to exits if compliance needs to be more strict
//but this program can make sense of less strict inputs so it does
char* valstr(int argc, char** argv)
{
	char* eloc = NULL;
	
	if(argc <= 1) 
	{
		puts("Fatal Error: Ran with too few arguments.");
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		puts("Fatal Error: Ran with too many arguments.");
		exit(EXIT_FAILURE);
	}
	
	for (int i = 0; i < strlen(argv[1]) - 1; i++)
	{
		if(isalpha(argv[1][i]) && (argv[1][i] != 'e' && argv[1][i] != 'E'))
		{
			puts("Warning: Illegal characters found on input.");
			puts("This is not a fatal error parsing will continue.");
			puts("Bad input will be considered blank.");
		}
	}
	
	if(!(eloc = strchr(argv[1],'e')))
	{	
		eloc = strchr(argv[1],'E');
	}

	if( (!isdigit(argv[1][0]) && !isdigit(argv[1][1])) || argv[1][0] == '.')
	{
		puts("Warning: Our notation requires the first character after the (optional) sign to be a single digit.");
		puts("This is not a fatal error parsing will continue.");
		puts("Bad input will be considered blank.");
	}
	
	if(eloc && strchr(eloc,'.'))
	{
		puts("Fatal Error: Our notation does not allow fractional exponents");
		exit(EXIT_FAILURE);
	}

	//if the e is included we need at least one digit after it
	if( eloc && (!isdigit((eloc)[1]) && !isdigit((eloc)[2])))
	{
		puts("Warning, our notation requires at least one digit after e and its optional sign.");
		puts("This is not a fatal error parsing will continue.");
		puts("Bad input will be considered blank.");
	}

	//if(argv[1][2] != '.' && argv[1][1] != '.')
	//{
	//	puts("Warning, our notation requires a dot after the first digit.");
	//}

	return eloc;
}


