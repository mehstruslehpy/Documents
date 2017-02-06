#include "global.h"

int lookahead;

parse()		/* Parses and translates expression list */
{
	lookahead = lexan();
	while (lookahead != DONE) {
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
			//emit(NUM, tokenval);
			romNum(NUM, tokenval);
			printf(" ");
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

//the production is from here:
//https://github.com/fool2fish/dragon-book-exercise-answers/blob/master/ch02/2.2/2.2.md
int romNum(int t, int tval)
{

	if ( tval >= 10000 ) {
		error("Number in romNum too large.");
	}
	if (tval >= 4000){
		int divbythous = tval / 1000;  //this should truncate which we want
		printf("_");
		romNum(NUM, divbythous);		
		printf("_");
		tval = tval - (divbythous * 1000);
	}
	if ( tval < 1000) {
		printf("");	//this is probably not needed
	} else if ( tval >= 1000 ) {
		while (tval >= 1000) {
			printf("M");
			tval = tval - 1000;
		}	
	} else {	
		error("Something has gone wrong in romNum()");
	}	
	hundr(t, tval);	
}

hundr(int t, int tval)
{
	if (tval >= 900) {
		printf("CM");
		tval = tval - 900;
	}
	//check for D (500)
	if (tval >= 500) {
		printf("D");
		tval = tval - 500;
	}
	if (tval >= 400){
		printf("CD");
		tval = tval - 400;
	}	
	if ( tval < 100) {
		printf("");	//this is probably not needed we could probably just do a semicolon here
	} else if ( tval >= 100 ) {
		while (tval >= 100) {
			printf("C");
			tval = tval - 100;
		}	
	} else {	
		error("Something has gone wrong in hundr()");
	}	
	tenr(t, tval);
}

tenr(int t, int tval)
{
	//check for 90
	if (tval >= 90) {
		printf("XC");
		tval = tval - 90;
	}
	//check for L (50)
	if (tval >= 50) {
		printf("L");
		tval = tval - 50;
	}
	//check for 40
	if (tval >= 40) {
		printf("XL");
		tval = tval - 40;
	}	
	if ( tval < 10) {
		printf("");	//this is probably not needed
	} else if ( tval >= 10 ) {
		while (tval >= 10) {
			printf("X");
			tval = tval - 10;
		}	
	} else {	
		error("Something has gone wrong in tenr()");
	}	
	digitr(t, tval);
}

digitr(int t, int tval)
{
	//check for 9
	if ( tval >= 9 ) {
		printf("IX");
		tval = tval - 9;
	}
	//check for V (5)
	if ( tval >= 5) {
		printf("V");
		tval = tval - 5;
	}
	//check for 4 
	if ( tval == 4 ) {	
		printf("IV");
		tval = tval - 4;
	}
	if ( tval < 5) {
		while (tval > 0) {
			printf("I");
			tval = tval - 1;
		}	
	} 	
}
