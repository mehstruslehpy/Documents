include(PushReturnAddress.m4)dnl
define(`ENTERFUNC',`//m4: implements the standard function call sequence 

dec d //m4: alloc a byte for ret addr on stk

PUSHRETADDR($2) 

jmpi $1 //m4: jmp to the function')dnl
