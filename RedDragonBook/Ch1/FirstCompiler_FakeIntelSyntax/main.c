#include "global.h"

main()
{
	printf("This program will output a sequence of instructions where  \n");
	printf("a = a op b is assumed to be true for all math instructions \n");
	printf("not all instructions output will translate directly to x86 \n");
	printf("Supported operations: mod, div, /, *, +, -, ()\n");
	printf("Please enter a semicolon separated list of infix expression: \n");
	init();
	parse();
	printf("\n");
	exit(0);
}
