/*
**	Score Assignment: This is a simple programming
**	Exercise that I will translate to C from a given
**	PseudoCode then I will translate it to ttpasm
*/

/*
**	Input: a grade in register a is assumed (for easy testing) this will also be stored into ram
**	Output: The string "your grade is %d" in ram where %d is an ascii code grade
*/

/*
**	Notes: ttp asm does not use /**/ comments so these will need to be removed
**	this code will be cleaned and optimized in another file prependend as .cleaned.asm
*/

//#include <stdio.h>
//
START:

//int main()
//{
//	int score = 75;
	//assume the grade is already
	//stored in register a
	ldi b SCORE
	st (b), a
//
//	printf("Your grade is: ");
//    
//	IF1:
IF1:
	ldi a, SCORE
	ld a, (a)
	ldi b, 60
	cmp a, b
	jci ELSEIF1
	jmpi IF2
//	if (score < 60) goto ELSEIF1;
//	goto IF2;
//  ELSEIF1:

ELSEIF1:
	ldi c, OUTPUT
	ldi d, 70
	st (c), d
//		printf("F");	//ascii 70
//    	goto ENDIF1;
	jmpi ENDIF1

//  IF2:
IF2:
	ldi a, SCORE
	ld a, (a)
	ldi b, 70
	cmp a, b
	jci ELSEIF2
	jmpi IF3
//  if (score < 70) goto ELSEIF2;
//	goto IF3;
//	ELSEIF2:
ELSEIF2:
	ldi c, OUTPUT
	ldi d, 68
	st (c), d
//      printf("D");	//ascii 68
//		goto ENDIF1;
	jmpi ENDIF1

//	IF3:
IF3:
	ldi a, SCORE
	ld a, (a)
	ldi b, 80
	cmp a, b
	jci ELSEIF3
	jmpi IF4
// 
//  if (score < 80) goto ELSEIF3;
//  goto IF4;
//	ELSEIF3:
ELSEIF3:
	ldi c, OUTPUT
	ldi d, 67
	st (c), d
//      printf("C");	//ascii 67
//		goto ENDIF1;
	jmpi ENDIF1

//	IF4:
IF4:
	ldi a, SCORE
	ld a, (a)
	ldi b, 90
	cmp a, b
	jci ELSEIF4
	jmpi IF5
//  if (score < 90) goto ELSEIF4;
//	goto IF5;

//  ELSEIF4:
ELSEIF4:
	ldi c, OUTPUT
	ldi d, 66
	st (c), d
//      printf("B");	//ascii 66
//    	goto ENDIF1;
	jmpi ENDIF1

//	IF5:
IF5:
	ldi c, OUTPUT
	ldi d, 65
	st (c), d
//      printf("A");	//ascii 65
//	ENDIF1:
ENDIF1:
	halt
//	printf("\n");
//}

STRING:
	byte 89 
	byte 111 
	byte 117 
	byte 114 
	byte 32 
	byte 103 
	byte 114 
	byte 97 
	byte 100 
	byte 101 
	byte 32 
	byte 105 
	byte 115 
	byte 89 
	byte 111 
	byte 117 
	byte 114 
	byte 32 
	byte 103 
	byte 114 
	byte 97 
	byte 100 
	byte 101 
	byte 32 
	byte 105 
	byte 115 
OUTPUT:
	byte 0
SCORE:
	byte: 0

