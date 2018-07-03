define(`PUSH',`//m4: push register $1 to the stk
dec d //m4: alloc a byte on stk 
st (d),$1')dnl
define(`POP',`//m4: pop from stk into register $1
ld $1,(d)
inc d //m4: dealloc a byte from the stk')dnl
