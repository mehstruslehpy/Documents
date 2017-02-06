#include "global.h"

int labelval = 0;
int lookahead;

parse()		/* Parses and translates expression list */
{
	lookahead = lexan();				//we should probably name this function stmt
	while (lookahead != DONE) {			//then wrap it in a new parse function
		stmt();
		printf(";\n");	//this is a shim that makes the output look cleaner to me
		match(';');
	}
}

expr()
{
	int t;
	term();
	while (1) {
		switch (lookahead) {
		case '+': case '-':
			t = lookahead;
			match(lookahead);
			term();
			emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

term()
{
	int t;
	factor();
	while (1) {
		switch (lookahead) {
		case '*': case '/': case DIV: case MOD:
			t = lookahead;
			match(lookahead);
			factor();
			emit(t, NONE);
			continue;
		default:
			return;
		}
	}
}

factor()
{
	switch (lookahead) {
		case '(':
			match('(');
			expr();
			match(')');
			break;
		case NUM:
			emit(NUM, tokenval);
			match(NUM);
			break;
		case ID:
			emit(ID, tokenval);
			match(ID);
			break;
		case IF_SYM:
			return;
		default:
			error("Syntax error in factor() in parser.c");
	}
}

match(int t)
{
	if (lookahead == t) {
		lookahead = lexan();
	} else {
		error("Syntax error");
	}
}

/* my custom code for parsing*/
stmt()
{
	labelval = labelval + 1;							//increment our global labelval to a new number for this stmt
	expr();
	if (lookahead == IF_SYM) {
		printf("\n; begin an if test expression\n\n");	    //print a comment
		match(lookahead);								//match our 'if'
		expr();		
		printf("\n;pop the top of stack into the EAX register\n");						//create the test expression
		printf(";if it is zero jump to the label, if not evaluate the \"then\" expression");									//create the test expression
		printf("\nPOP EAX");									//create the test expression
		printf("\nGOFALSE OUT%d\n\n", labelval);		//output a conditional jump
		match(lookahead);   							//match then
		expr();											//eval output expression
		printf("\nLABEL: OUT%d\n\n", labelval);								//output the false condition lable
	}
}
