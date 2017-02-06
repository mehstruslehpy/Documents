#include "global.h"

int lookahead;

parse()		/* Parses and translates expression list */
{
	lookahead = lexan();				//we should probably name this function stmt
	while (lookahead != DONE) {			//then wrap it in a new parse function
		if (lookahead == IF_SYM) {		
			printf("\nIF (\n");			//emit code somehow...
			match(lookahead);			//match if
			expr();						//evaluate expr1
			printf("\n) then (\n\n");	//emit code somehow...
			match(lookahead);   		//match then
			expr();						//eval expr2
			printf("\n)\n");			//end the stmt
			match(';');
		}
		expr();
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
	printf("IF_HERE ");
	expr();
	printf("THEN_HERE");
}
