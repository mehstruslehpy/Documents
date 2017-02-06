#include "global.h"

main()
{
	printf("Please enter an infix expression using decimal numbers: \n");
	printf("Note: Roman numeral \"overlines\" are depicted by surrounding numbers with underscores\n");
	init();
	parse();
	printf("\n");
	exit(0);
}
