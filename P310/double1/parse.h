#ifndef PARSE_H
#define PARSE_H
#include <stdint.h>
#include "number.h"

struct ParseState
{
	const char *ptr;
	struct Number *pn;
};

int parse(const char *str, struct Number *pn);

#endif
