START:
//int main()
//{
//int a = 0;
	ldi a, A
	ldi b, 0
	ld (a), b

//int c = 22;
	ldi a, C
	ldi b, 22
	ld (a), b

//int b = 12;
	ldi a, B
	ldi b, 12
	ld (a), b

BEGINWHILE1:
//if (c<a) goto ENDWHILE; 
	ldi a, C
	ld a, (a)
	ldi b, A
	ld b, (b)
	cmp a, b
	jli ENDWHILE

//if (a<b) goto BEGINWHILE2;
	ldi a, A
	ld a, (a)
	ldi b, B
	ld b, (b)
	cmp a, b
	jli BEGINWHILE2 

//if (b<a) goto BEGINWHILE2;
	cmp b, a
	jli BEGINWHILE2 

//goto ENDWHILE;
	jmpi ENDWHILE

BEGINWHILE2:
//printf("a: %d\n",a);
//a++;
	ldi a, A
	cpr b, a
	ld a, (a)
	inc a
	st (b), a

//goto BEGINWHILE1;
	jmpi BEGINWHILE1
ENDWHILE:
	halt
//printf("Done a: %d\n",a);
//}

A:
	byte 0
B:
	byte 0
C:
	byte 0
