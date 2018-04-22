/*
**	Score Assignment: This is a simple programming
**	Exercise that I will translate to C from a given
**	PseudoCode then I will translate it to ttpasm
*/

#include <stdio.h>

int main()
{
    int score = 75;

	printf("Your grade is: ");
    
	IF1:
	if (score < 60) goto ELSEIF1;
	goto IF2;
    ELSEIF1:
        printf("F");	//ascii 70
    	goto ENDIF1;
    IF2:
    if (score < 70) goto ELSEIF2;
	goto IF3;
	ELSEIF2:
        printf("D");	//ascii 68
    	goto ENDIF1;
	IF3:
    if (score < 80) goto ELSEIF3;
    goto IF4;
	ELSEIF3:
        printf("C");	//ascii 67
    	goto ENDIF1;
	IF4:
    if (score < 90) goto ELSEIF4;
	goto IF5;
    ELSEIF4:
        printf("B");	//ascii 66
    	goto ENDIF1;
	IF5:
        printf("A");	//ascii 65
	ENDIF1:
	printf("\n");
}
