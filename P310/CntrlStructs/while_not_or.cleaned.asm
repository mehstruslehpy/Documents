START:
	ldi a, A
	ldi b, 0
	ld (a), b

	ldi a, C
	ldi b, 22
	ld (a), b

	ldi a, B
	ldi b, 12
	ld (a), b

BEGINWHILE1:
	ldi a, C
	ld a, (a)
	ldi b, A
	ld b, (b)
	cmp a, b
	jli ENDWHILE

	ldi a, A
	ld a, (a)
	ldi b, B
	ld b, (b)
	cmp a, b
	jli BEGINWHILE2 

	cmp b, a
	jli BEGINWHILE2 

	jmpi ENDWHILE

BEGINWHILE2:
	ldi a, A
	cpr b, a
	ld a, (a)
	inc a
	st (b), a

	jmpi BEGINWHILE1
ENDWHILE:
	halt

A:
	byte 0
B:
	byte 0
C:
	byte 0
