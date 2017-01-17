#include <stdio.h> /*stdio - we will probably need it*/
#include <ctype.h> /*loads file with predicate isdigit*/
int lookahead;

//call main grab characters and evaluate then print a newline
main()
{
	lookahead = getchar();
	expr();
	putchar('\n');
	exit(1);
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
