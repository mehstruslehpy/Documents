#include "global.h"

emit(int t, int tval)
{
	switch (t) {
		case '+': case '-': case '*': case '/':
			printf("Pop two values into registers and %c then push the result onto the stack\n", t); 
			break;
		case DIV:
			printf("Pop two values into registers and DIV then push the result onto the stack\n");
			break;
		case MOD:
			printf("Pop two values into registers and MOD then push the result onto the stack\n");
			break;
		case NUM:
			printf("Push %d to stack\n", tval);
			break;
		case ID:
			printf("%s\n", symtable[tval].lexptr);
			break;
		default:
			printf("token %d, tokenval %d\n", t, tval);
	}
}
