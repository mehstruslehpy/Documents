#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024
//max length because im too dumb too think of a better way
const int MAXLENGTH = 100;

int helpMenu();
int initQs(char **qs, int sz);
int initAs(char **as, int sz);
int beginTest(char **qs, char **as, int sz);
int readQuiz(char **qs, char **as);
int writeQuiz(char **qs, char **as, int sz);
int clearScreen();
int countlines(FILE *fin);

int main()
{
	char replIn;
	int isLoaded = 0;
	int size = 0;
	char **questions;
	char **answers;
	answers = (char**) malloc(sizeof(char**));
	questions = (char**) malloc(sizeof(char**));

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

		//write quiz or error
		if ( (replIn == 'w') && (isLoaded == 0) )
		{
			printf("Error! No quiz has been created. \n");
		}
		else if ( (replIn == 'w') && (isLoaded == 1) )
		{	
			writeQuiz(questions, answers, size);
		}
		
		//read quiz or error
		if ( (replIn == 'r') )
		{
			//this is a case where we will definitely need error checking
			//i will add that later though	
			size = readQuiz(questions, answers);
			isLoaded = 1;
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
	//free(questions);
	//free(answers);
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
	printf("		w: write quiz to file\n");
	printf("		r: read quiz from file\n");
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
	printf("Percentage: %i \n", ( (count * 100) / sz ));
	free(input);
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

int writeQuiz(char **qs, char **as, int sz)
{
	char size[20]; 
	sprintf(size, "%d", sz);
	FILE *fp = NULL;
	char input[32];

	//prompt for a filename
	//the calls to scanf earlier lead to a \n in stdin
	//calling getchar allows me to cleanly ask for input
	//without immediately passing in empty filenames
	getchar();
	printf("Enter a filename: \n");
	fgets(input, 32, stdin);
	input[strcspn(input, "\n")] = '\0';

	//opening the file pointer in append mode
	fp = fopen(input, "a");

	for(int i = 0; i < sz; i++)
	{
		//"-Q" Delimiter
		fputs("-Q", fp);
		//output the question
		fputs(qs[i], fp);
	}
	
	for(int i = 0; i < sz; i++)
	{
		//"-A" Delimiter
		fputs("-A", fp);
		//output the question
		fputs(as[i], fp);
	}
	
	//output EOF
	fclose(fp);
	return 0;
}

int readQuiz(char **qs, char **as)
{
	char *lninterim = malloc( sizeof(char) * MAXLENGTH );
	int lines;
	//char size[20]; 
	//sprintf(size, "%d", sz);
	//printf("%s", lninterim);
	FILE *fp = NULL;
	char input[32];
	
	//input the file name to be read
	getchar();
	printf("Enter a filename: \n");
	fgets(input, 32, stdin);
	input[strcspn(input, "\n")] = '\0';
	
	//opening the file pointer in read mode
	fp = fopen(input, "r");
	lines = countlines(fp);	
	printf("Line count: %d\n", lines);
	printf("Beginning read... \n");

	//this will be messed up if lines are not even..
	*as = (char *) malloc( (lines / 2) * sizeof(char*));
	*qs = (char *) malloc( (lines / 2) * sizeof(char*));

	//allocate the char arrays for questions
	for(int i = 0; i <= ((lines / 2) - 1); i++)
	{
		qs[i] = malloc( (sizeof(char) * MAXLENGTH) );
	}

	//allocate the char arrays for answers
	for(int i = 0; i <= ((lines / 2) - 1); i++)
	{
		as[i] = malloc( (sizeof(char) * MAXLENGTH) );
	}
	
	//trying to start from the beginning
	rewind(fp);

	//read each answer into qs[i]
	for(int i = 0; i <= ((lines / 2) - 1); i++)
	{
		fgets(lninterim, sizeof(char) * MAXLENGTH, fp);
		printf("Question Line read: %s", lninterim);
		//remove delimiters
		memmove(lninterim, lninterim + 2, MAXLENGTH);
		printf("Delim stripped: %s", lninterim);
		strcpy(qs[i], lninterim);	

	}
	
	//read each answer into as[i]
	for(int i = 0; i <= ((lines / 2) - 1); i++)
	{
		fgets(lninterim, sizeof(char) * MAXLENGTH, fp);
		printf("Answer line read: %s", lninterim);
		//remove delimiters
		memmove(lninterim, lninterim + 2, MAXLENGTH);
		printf("Delim stripped: %s", lninterim);
		strcpy(as[i], lninterim);	
	}

	free(lninterim);
	return (lines / 2);
}

//this code is also stolen from so
int countlines (FILE *fin)
{
    int  nlines  = 0;
    char line[BUFFSIZE];

    while(fgets(line, BUFFSIZE, fin) != NULL) {
        nlines++;
    }

    return nlines;
}
