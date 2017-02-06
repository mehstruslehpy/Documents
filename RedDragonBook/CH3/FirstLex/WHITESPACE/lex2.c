#include <stdio.h>      
#include <ctype.h>  
#include <string.h>

#define BUF 10000

char inChar[BUF];
int x = 0;
int y = 1;
int z = 0;

int main(int argc, char **argv)
{
	//check tokens
	while ( x != BUF && y <= argc - 1 ) {

		//check characters		
		while (z != BUF && x != BUF && y <= argc - 1) {  

			//check for newline
			if (argv[y][z] == '\n') {
				break;
			}
					
			if (argv[y][z] == 0) {
				break;
			}
			if (argv[y][z] == '\t') {
				break;
			}
			inChar[x] = argv[y][z];
			printf("CHAR OUT: %c AT INDEX: %d\n", inChar[x], x);
			z = z + 1;
			x = x + 1;
		}
		//printf("**WHITESPACE**\n");
		
		if (inChar[x] == '\n') {
			break;
		}
		y = y + 1;
		//x = x + 1;
		z = 0;	
	}

	printf("INTERNAL OUT: %s\n", inChar);
	//printf("INPUT BUFFER: %s\n", argv[1]);
}
