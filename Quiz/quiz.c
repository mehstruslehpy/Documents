#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//max length because im too dumb too think of a better way
const int MAXLENGTH = 100;

int helpMenu();
int initQs(char **qs, int sz);
int initAs(char **as, int sz);
int beginTest(char **qs, char **as, int sz);
int clearScreen();

int main()
{
	char replIn;
	int isLoaded = 0;
	int size = 0;
	char **questions;
	char **answers;
/*
	REPL OPTIONS
		c: create
		s: start
		x: clear screen
		h: help
		q: quit

NOTE: I'd like to add some more features later, I doubt file input and output would be too crazy.
*/
	printf("welcome to my quiz program!\n");
	printf("This program was made by WPV for CISP300!\n");
	helpMenu();
	replIn = getchar();	
	//printf("\n");
	while( replIn != 'q' )
	{

		//create quiz
		if (replIn == 'c')
		{
			printf("Enter your question and answer pool size: \n");
			scanf("%d", &size);
			//the number of elements
			questions = malloc(size * sizeof(char*));
			answers = malloc(size * sizeof(char*));
			initQs(questions, size);
			initAs(answers, size);
			isLoaded = 1;
		}

		//print help
		if (replIn == 'h')
		{
			helpMenu();
		}

		//take quiz or error
		if ( (replIn == 's') && (isLoaded == 0) )
		{
			printf("Error! No quiz has been created. \n");
		}
		else if ( (replIn == 's') && (isLoaded == 1) )
		{	
			printf("Beginning test.. \n");
			beginTest(questions, answers, size);
		}

		//screen clearing hack (maybe cross platform???)
		if (replIn == 'x')
		{	
			clearScreen();
		}


	printf(">");
	replIn = getchar();	
	}

	//be sure to free at the end..
	//I might be doing this wrong but memory leaks wont kill me
	//plus valgrind says im good and I don't segfault this way
	for(int i = 0; i < (size - 1); i++)
	{
		free(answers[i]);
	}
	for(int i = 0; i < (size - 1); i++)
	{
		free(questions[i]);
	}
	return 0;
}

int initQs(char **qs, int sz)
{
	char* input = malloc( sizeof(char) * MAXLENGTH );
	
	for(int i = 0; i <= (sz - 1); i++)
	{
		//allocate the individual elements
		qs[i] = malloc( (sizeof(char) * MAXLENGTH) );
	}

	for(int i = 0; i <= (sz - 1); i++)
	{
		if(i == 0)	
		{
			qs[i] = malloc( (sizeof(char) * MAXLENGTH) );
			fgets(input, sizeof(char) * MAXLENGTH, stdin);
			strcpy(qs[i], input);	
		}

		printf("Question %d \n", i);
		fgets(input, sizeof(char) * MAXLENGTH, stdin);
		strcpy(qs[i], input);	
	}
	
	printf("Printing question list... Press enter to continue\n");	

	for(int i = 0; i <= (sz - 1); i++)
	{
		printf("Question 1: %s", qs[i]);
	}	

	printf("\n");

	free(input);
	
	return 0;
}

int initAs(char **as, int sz)
{
	char* input = malloc( sizeof(char) * MAXLENGTH );
	
	for(int i = 0; i <= (sz - 1); i++)
	{
		as[i] = malloc( (sizeof(char) * MAXLENGTH) );
	}

	for(int i = 0; i <= (sz - 1); i++)
	{
		//not sure why it wants to skip these so badly...
		if(i == 0)	
		{
			as[i] = malloc( (sizeof(char) * MAXLENGTH) );
			fgets(input, sizeof(char) * MAXLENGTH, stdin);
			strcpy(as[i], input);	
		}

		as[i] = malloc( (sizeof(char) * MAXLENGTH) );
		printf("Answer %d \n", i);
		fgets(input, sizeof(char) * MAXLENGTH, stdin);
		strcpy(as[i], input);
	}

	printf("Printing answer list...\n");	

	for(int i = 0; i <= (sz - 1); i++)
	{
		printf("Answer: %s", as[i]);
	}	

	printf("\n");

	free(input);
	
	return 0;
}

int helpMenu()
{
	printf("\nAvailable commands:\n");
	printf("		q: quit\n");
	printf("		c: create a quiz\n");
	printf("		s: start a quiz\n");
	printf("		x: clear the screen\n");
	printf("		h: print this menu\n");
	
	return 0;
}

int beginTest(char **qs, char **as, int sz)
{
	char* input = malloc( sizeof(char) * MAXLENGTH );
	int count = 0;
	//test priming input?
	fgets(input, sizeof(char) * MAXLENGTH, stdin);

	for(int i = 0; i < sz; i++)
	{
		printf("Question: %s",qs[i]);
		fgets(input, sizeof(char) * MAXLENGTH, stdin);
		
		if( strcmp(as[i], input) == 0 )
		{
			count = count + 1;
		}
	}	
	printf("You got %i out %i \n", count, sz);
	printf("Percentage: %i ", ( (count * 100) / sz ));
	return count;
}

int clearScreen()
{
	//dirty hacks
	//Windows
	system("cls");
	//*nix
	system("clear");
	return 0;
}

