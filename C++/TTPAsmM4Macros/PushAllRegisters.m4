define(`PUSHALLREGD',
`//m4: push all the registers
dec d
st (d),a 
dec d
st (d),b 
dec d
st (d),c 
dec d
st (d),d')dnl
define(`PUSHALLREG',
`//m4: push all the registers except d
dec d
st (d),a 
dec d
st (d),b 
dec d
st (d),c')dnl
