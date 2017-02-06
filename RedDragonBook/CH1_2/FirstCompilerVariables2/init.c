#include "global.h"

//lexptr, tokenid, offset
struct entry keywords[] = {
	"div", DIV, 0, 0,
	"mod", MOD, 0, 0,
	"if", IF_SYM, 0, 0,
	"then", THEN_SYM, 0, 0,
	"while", WHILE_SYM, 0, 0,
	"do", DO_SYM, 0, 0,
	":=", ASSIGN_SYM, 0, 0,
	0, 0
};

init()
{
	struct entry *p;
	for (p = keywords; p->token; p++) {
		insert(p->lexptr, p->token);
	}
}
