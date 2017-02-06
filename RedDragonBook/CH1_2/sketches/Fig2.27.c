#include <stdio.h>  /*stdio - we will probably need it*/
#include <stdlib.h> /*stdlib - we will probably need it*/
#include <ctype.h>  /*loads file with predicate isdigit*/
#define NUM 256
int lookahead;

int  main()
{
		printf("Please input an infix expression to be translated: \n");
		lookahead = getchar();
		expr();
		putchar('\n');
		return 1;
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

factor()
{
	if (lookahead == '(') {
		match('(');
		expr();
		match(')')
	} else if (lookahead == NUM){
		printf("%d", tokenval); 
		match(NUM);
	}
	else error();
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
