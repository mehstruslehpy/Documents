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

/*CUSTOM DEFINITIONS FOR IF then ELSE*/
//extern int labelval = 0;		//we will use this to generate unique label names
#define IF_SYM 261
#define THEN_SYM 262
#define WHILE_SYM 263
#define DO_SYM 264
#define ASSIGN_SYM 265

extern int pushPop;	//this will keep track of how many items are on the stack at a time
