#include <stdio.h>  /*stdio - we will probably need it*/
#include <stdlib.h> /*stdlib - we will probably need it*/
#include <ctype.h>  /*loads file with predicate isdigit*/
int lookahead;

//this will not work for multidigit terminals..
//call main grab characters and evaluate then print a newline
main(int argc, char **argv)
{
	//check for command line arguments
	//if none ask for an input expression
	if (argc == 1) {
		printf("Please input an infix expression to be translated: \n");
		lookahead = getchar();
		expr();
		putchar('\n');
		exit(1);
	} else if (argc != 1){		
		printf("CommandLine args are not implemented yet!\n");
		//this all needs reimplemented to read the command line arguments
		//since right now it gets each value by reading values via getchar
		//we want it to iterate through argv[1]'s characters though...
		//lookahead = argv[1];
		//expr();
	} else {
		printf("Oops..");
		exit(1);
	}
}

expr()
{
	term();
	while (1)
	if (lookahead == '+') {	
		match('+');
		term();
		putchar('+');
	} else if (lookahead == '-') {
		match('-');
		term();
		putchar('-');
	}
	else break;	
}

term()
{
	if (isdigit(lookahead)) {
		putchar(lookahead);
		match(lookahead);
	}
	else error();
}

match(int t)
{
	if (lookahead == t)
		lookahead = getchar();
	else error();
}

error() 
{
	printf("syntax error \n");
	exit(1);
}

/*
	#infix to postfix translation scheme#
	expr	-> term rest
	rest	-> + term { print('+') } rest
			|  - term { print('-') } rest
			| empty
	term	-> 0 { print('0') }
		...
		...
		...
	term	-> 9 { print('9') }

*/
