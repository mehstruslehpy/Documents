START:
//int a = 77;
	ldi a, A
	ldi b, 77
	st (a), b

//int b = 5;
	ldi a, B
	ldi b, 5
	st (a), b

//int c = 23;
	ldi a, C
	ldi b, 23
	st (a), b

//if (1<b) goto IF;
	ldi a, B
	ld a, (a)
	ldi b, 1
	cmp b, a
	jci IF

//if (b==1) goto IF;
	ldi a, B
	ld a, (a)
	cmp a, b
	jzi IF

//if (c==a) goto IF;
	ldi a, B
	ld a, (a)
	ldi b, C
	ld b, (b)
	cmp a, b
	jzi IF

//goto ELSE;
	jmpi ELSE

IF:
//printf("case 1: a = 99\n");
//a = 99;
	ldi a, A
	ldi b, 99
	st (a), b
//goto END;
	jmpi END

ELSE:
//printf("case 2: a = 15\n");
//a = 15;
	ldi a, A
	ldi b, 15
	st (a), b

END:
	halt

A:
	byte 0
B:
	byte 0
C:
	byte 0
