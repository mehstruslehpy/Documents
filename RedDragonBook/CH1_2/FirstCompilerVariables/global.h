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
	int offset;
	int mypushpop;
};

struct entry symtable[]; /* symbol table */

/*CUSTOM DEFINITIONS*/
#define IF_SYM 261
#define THEN_SYM 262
#define WHILE_SYM 263
#define DO_SYM 264
#define ASSIGN_SYM 265

extern int pushPop;	//this keeps track of the pushes and pops throughout the whole program it is not used now but could be used later
int offset;			//this is used as an offset into the symboltable to refer to variables
