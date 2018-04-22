// Score Assignment: This is a simple programming
// Exercise that I will translate to C from a given
// PseudoCode then I will translate it to ttpasm

// Input: a score in register a is assumed (for easy testing) this will also be stored into ram
// Output: The string "your grade is %d" in ram where %d is an ascii code grade
//		   The score itself will also be stored in ram

START:
	//assume the grade is already
	//stored in register a
	ldi b, SCORE
	st (b), a
	ldi c, GRADE

IF1:
	ldi b, 60
	cmp a, b
	jci ELSEIF1
	jmpi IF2
ELSEIF1:
	ldi d, 70
	st (c), d
	jmpi ENDIF1

IF2:
	ldi b, 70
	cmp a, b
	jci ELSEIF2
	jmpi IF3
ELSEIF2:
	ldi d, 68
	st (c), d
	jmpi ENDIF1

IF3:
	ldi b, 80
	cmp a, b
	jci ELSEIF3
	jmpi IF4
ELSEIF3:
	ldi d, 67
	st (c), d
	jmpi ENDIF1

IF4:
	ldi b, 90
	cmp a, b
	jci ELSEIF4
	jmpi IF5
ELSEIF4:
	ldi d, 66
	st (c), d
	jmpi ENDIF1

IF5:
	ldi d, 65
	st (c), d
ENDIF1:
	halt

PAD1:
	byte 0
	byte 0
	byte 0
	byte 0
SCORE:
	byte: 0
PAD2:
	byte 0
	byte 0
	byte 0
	byte 0
SCORE:
	byte: 0

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
	byte 32
GRADE:
	byte 0
