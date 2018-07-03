define(`PUSHRETADDR',
`//m4: push the return address to the stack, clobbers the a register
ldi a, $1 //m4: $1 is the return address
dec d //m4: alloc space for retaddr
st (d),a //m4: push the retaddr')dnl
dnl here's an example
dnl PUSHRETADDR(myreturnaddress)
