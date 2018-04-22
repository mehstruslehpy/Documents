START:
//int a = 0;
ldi a, A
ldi b, 0
st a, b

//int b = -1;
//-1_10 = C_2(00000001_2)
//-1_10 = 11111111_2
//11111111_2 = 255
ldi a, B
ldi b, 255
st (a), b

//int c = 7;
ldi a, C
ldi b, 7
st (a), b

//if (b<=1 && c!=a)
//if (1 < b) goto ELSE;
ldi a, B
ld a, (a)
ldi b, 1
cmp b, a
jli ELSE

//if (c<a) goto IF;
ldi a, C
ld a, (a)
ldi b, A
ld b, (b)
cmp a, b
jli IF

//if (a<c) goto IF;
cmp b, a
jli IF

//goto ELSE;
jmpi ELSE

IF:
//printf("case 1: a = 99\n");
//a = 99;
ldi a, A
ldi b, 99
st (a), b
jmpi ENDIF
//goto ENDIF;

ELSE:
//printf("case 2: a = 15\n");
//a = 15;
ldi a, A
ldi b, 15
st (a), b
ENDIF:
halt

A:
byte 0
B:
byte 0
C:
byte 0
