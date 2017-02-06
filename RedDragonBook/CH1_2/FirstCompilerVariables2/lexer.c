#include "global.h"

char lexbuf[BSIZE];
int lineno = 1;
int tokenval = NONE;

int lexan()		/* lexical analyser */
{
	int t;
	while (1) {
		t = getchar();
		if (t == ' ' || t == '\t' ) 
			; 						/*strip out whitespace*/
		else if (t == '\n')
			lineno = lineno + 1;
		else if (isdigit(t)) {		/*t is a digit*/
			ungetc(t, stdin);
			scanf("%d", &tokenval);
			return NUM;
		}
		else if (isalpha(t)) {	
			int p, b = 0;
			while (isalnum(t)) {	/*t is alphanumeric*/
				lexbuf[b] = t;
				t = getchar();
				b = b + 1;
				if (b >= BSIZE)
					error("Compiler error"); //modified to add in the line number
			}
			lexbuf[b] = EOS;
			if (t != EOF)
				ungetc(t, stdin);
			p = lookup(lexbuf);
			if (p == 0)
				p = insert(lexbuf, ID);
			tokenval = p;
			//if (offset == NULL)
			offset = p;
			return symtable[p].token;
		}
		else if (t == EOF)
			return DONE;
		else {
			tokenval = NONE;
			return t;
		}
	}
}
