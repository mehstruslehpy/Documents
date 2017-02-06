#include "global.h"

int labelval = 0;
int lookahead;
int pushPop = 0;

parse()		/* Parses and translates expression list */
{
	lookahead = lexan();				//we should probably name this function stmt
	while (lookahead != DONE) {			//then wrap it in a new parse function
		printf(";start of statement\n");	//this is a shim that makes the output look cleaner to me
		stmt();
		printf(";end of statement\n");	//this is a shim that makes the output look cleaner to me
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
	//expr();
	switch (lookahead) {
		case IF_SYM:
			printf("\n;beginning of if stmt\n");	    //print a comment
			match(lookahead);								//match our 'if'
			expr();		
			printf("\n;pop the result off the stack into the EAX register\n");						//create the test expression
			printf(";if it is zero jump to the label, if not evaluate the \"then\" expression");									//create the test expression
			printf("\nPOP EAX"); pushPop--;									//create the test expression
			printf("\nGOFALSE Out%d\n\n", labelval);		//output a conditional jump this will match x86 intel syntax more closely if we do jz
			match(lookahead);   							//match then
			stmt();											//eval output expression
			printf("\nLABEL: Out%d\n", (labelval - 1));								//output the false condition lable
			printf("\n;end of if stmt\n");	    //print a comment
			break;	    //print a comment
		case WHILE_SYM:
			printf(";beginning of while stmt\n");	    //print a comment
			match(lookahead);								//match our 'while'
			printf("LABEL: Test%d\n", labelval);			//print the label for the start of the loop
			expr();											//expression to test		
			printf(";pop the result off the stack into the EAX register\n");						//create the test expression
			printf(";if it is zero jump to the Out label, if not evaluate the \"do\" expression");									//create the test expression
			printf("\nPOP EAX"); pushPop--;					//pop for test 
			printf("\nGOFALSE Out%d\n\n", labelval);		//if the expression above ends up false jump out of the loop
			match(lookahead);   							//match 'do'
			stmt();
			printf("GOTO Test%d", (labelval - 1));			//JMP TO TOP
			printf("\nLABEL: Out%d\n", (labelval - 1));			//THE OUT LABEL
			printf(";end of while stmt\n");	    //print a comment
			break;
		default:
			expr();
	}
	return;
}
