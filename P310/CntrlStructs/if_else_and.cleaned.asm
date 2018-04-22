START:
	ldi a, A
	ldi b, 0
	st (a), b

	ldi a, B
	ldi b, 255
	st (a), b

	ldi a, C
	ldi b, 7
	st (a), b

	ldi a, B
	ld a, (a)
	ldi b, 1
	
	cmp b, a
	jli ELSE

	ldi a, C
	ld a, (a)
	ldi b, A
	ld b, (b)
	cmp a, b
	jli IF

	cmp b, a
	jli IF
	jmpi ELSE
IF:
	ldi a, A
	ldi b, 99
	st (a), b
	jmpi ENDIF
ELSE:
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
