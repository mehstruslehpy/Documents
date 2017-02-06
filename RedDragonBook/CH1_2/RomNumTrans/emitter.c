#include "global.h"

emit(int t, int tval)
{
	switch (t) {
		case '+': case '-': case '*': case '/':
			printf("%c ", t); 
			break;
		case DIV:
			printf("DIV ");
			break;
		case MOD:
			printf("MOD ");
			break;
		case NUM:
			printf("%d ", tval);
			break;
		case ID:
			printf("%s\n", symtable[tval].lexptr);
			break;
		default:
			printf("token %d, tokenval %d\n", t, tval);
	}
}
