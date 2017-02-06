#include <stdlib.h>
#include "global.h"

error(char *m) 
{
	fprintf(stderr, "line %d: %s\n", lineno, m);
	exit(1);
}
