#include <stdio.h>

int main() {
	
	char x[3];
	printf("sizeof char ptr: %d \n", sizeof(char *));
	printf("sizeof x: %d \n", sizeof(x[0]));
	printf("sizeof int: %d \n", sizeof(int));
	return 0;
}
