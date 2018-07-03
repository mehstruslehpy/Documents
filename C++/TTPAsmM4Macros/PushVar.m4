define(`PUSHVAR',
`//m4: push the constant var $1 to the stack, clobbers a
ldi a, $1
dec d
st (d),a
')dnl
