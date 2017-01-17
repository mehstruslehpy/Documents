/**********************************  global.h  **********************************************************************/
#include <stdio.h>	/* loads io routines */
#include <ctype.h>	/* loads character test routines */ 
#include <string.h>

#define BSIZE 128	/* buffer size */
#define NONE -1
#define EOS '\0'

#define NUM 256
#define DIV 257
#define MOD 258
#define ID 259
#define DONE 260

int tokenval; 		/* value of token attribute */
int lineno;

struct entry { 		/* form of symbol table entry */
	char *lexptr;
	int token;
};

struct entry symtable[]; /* symbol table */

