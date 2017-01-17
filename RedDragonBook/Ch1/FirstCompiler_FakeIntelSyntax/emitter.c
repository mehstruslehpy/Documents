#include "global.h"

emit(int t, int tval)
{
	switch (t) {
		case '+':															//we have to split these up for them to work how I want..
			printf("POP EBX\nPOP EAX\nADD EAX, EBX\nPUSH EAX\n", t); 
			break;
		case '-':
			printf("POP EBX\nPOP EAX\nSUB EAX, EBX\nPUSH EAX\n", t); 
			break;
		case '*':
			printf("POP EBX\nPOP EAX\nMUL EAX, EBX\nPUSH EAX\n", t); 
			break;
		case '/':
			printf("POP EBX\nPOP EAX\nDIV EAX, EBX\nPUSH EAX\n", t); 
			break;
		case DIV:
			printf("POP EBX\nPOP EAX\nDIV EAX EBX\nPUSH EAX\n", t); 
			break;
		case MOD:
			printf("POP EBX\nPOP EAX\nMOD EAX, EBX\nPUSH EAX\n", t); 
			break;
		case NUM:
			printf("PUSH %d\n", tval);
			break;
		case ID:
			printf("%s\n", symtable[tval].lexptr);
			break;
		default:
			printf("token %d, tokenval %d\n", t, tval);
	}
}
