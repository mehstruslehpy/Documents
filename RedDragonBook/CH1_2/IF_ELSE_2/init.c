#include "global.h"

struct entry keywords[] = {
	"div", DIV,
	"mod", MOD,
	"if", IF_SYM,
	"then", THEN_SYM,
	0, 0
};

init()
{
	struct entry *p;
	for (p = keywords; p->token; p++) {
		insert(p->lexptr, p->token);
	}
}
