#include "global.h"

emit(int t, int tval)
{
	switch (t) {
		case '+': 
			printf("\nPOP EBX\n", t);   pushPop--;
			printf("POP EAX\n", t); 	pushPop--;
			printf("ADD EAX, EBX     ;EAX = EAX %c EBX\n", t, t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case '-': 			
			printf("\nPOP EBX\n", t); pushPop--; 
			printf("POP EAX\n", t);  pushPop--;
			printf("SUB EAX, EBX     ;EAX = EAX %c EBX\n", t, t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case '*': 			
			printf("\nPOP EBX\n", t); pushPop--;
			printf("POP EAX\n", t); pushPop--;
			printf("MUL EAX, EBX     ;EAX = EAX %c EBX\n", t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case '/': 
			printf("\nPOP EBX\n", t); pushPop--;
			printf("POP EAX\n", t); pushPop--;
			printf("DIV EAX, EBX     ;EAX = EAX %c EBX\n",t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case DIV:															//maybe I will add an idiv instruction?
			printf("\nPOP EBX\n", t); pushPop--;
			printf("POP EAX\n", t); pushPop--;
			printf("DIV EAX, EBX     ;EAX = EAX div EBX, which is equiv to EAX = EAX / EBX\n",t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case MOD:
			printf("\nPOP EBX\n", t); pushPop--;
			printf("POP EAX\n", t); pushPop--;
			printf("MOD EAX, EBX     ;EAX = EAX mod EBX\n",t);
			printf("PUSH EAX         ;Push the result onto the stack\n\n", t); pushPop++;
			break;
		case NUM:
			printf("PUSH %d\n", tval); pushPop++;
			break;
		case ID:
            printf("RVALUE '%s'     ;push contents of data location %s \n", symtable[tval].lexptr, symtable[tval].lexptr);
			break;
		default:
			printf("token %d, tokenval %d\n", t, tval);
	}
}
