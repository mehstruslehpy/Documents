define(`POPALLREGD',
`//m4: pop all the registers
ld d,(d)
inc d
ld c,(d)
inc d
ld b,(d)
inc d
ld a,(d)
inc d')dnl
define(`POPALLREG',
`//m4: pop all the registers except d
ld c,(d)
inc d
ld b,(d)
inc d
ld a,(d)
inc d')dnl
