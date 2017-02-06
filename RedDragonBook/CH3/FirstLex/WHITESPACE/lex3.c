#include <stdio.h>      
#include <ctype.h>  
#include <string.h>

#define BUF 1000
//globals
//globals
char inChar[BUF];
int x = 0;

int main(int argc, char **argv)
{
	//get and print each character
	while ( x != BUF ) {
		inChar[x] = getchar();

		//this is a terrible way to do this
		if ( inChar[x] == ':') {
			inChar[x] = getchar();
			if ( inChar[x] == 'Q') {
				inChar[x] = getchar();
				if ( inChar[x] == 'U') { 
									inChar[x] = 0x7F;
									printf("\nINTERNAL OUT: %s\n", inChar);
									return 0;
				}
			}
			inChar[x] = getchar();
		}

		
		while (inChar[x] == '\n') {
			inChar[x] = getchar();	//if a space is entered get the next character
		}
		while (inChar[x] == ' ') {
			inChar[x] = getchar();	//if a space is entered get the next character
		}
		while (inChar[x] == '\t') {
			inChar[x] = getchar();	//same as spaces
		}

		//printf("CHAR OUT: %c AT INDEX: %d\n", inChar[x], x);
		x = x + 1;
	}

	//printf("INTERNAL OUT: %s\n", inChar);
	//printf("INPUT BUFFER: %s\n", argv[1]);
}
