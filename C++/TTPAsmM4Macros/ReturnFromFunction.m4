dnl RETURNFROMFUNC automates returning from a function
dnl you just need to specify how many items to pop from the stack 
dnl til you reach the return address
include(AsmTimeForLoop.m4)
define(`RETURNFROMFUNC',
`ifelse(`NONE',$1,`//m4: return from function, clobbers b
ld b,(d) //m4: load return address to reg b
inc d //m4: pop return address
jmp b //m4: jump out of function',
`//m4: return from function, clobbers b
forloop(`i',1,$1,`inc d
')dnl
//m4: pop $1 items from stack first
ld b,(d) //m4: load return address to b
inc d //m4: pop return address
jmp b //m4: jump out of function')'
)dnl
