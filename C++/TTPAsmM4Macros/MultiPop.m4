include(AsmTimeForLoop.m4)dnl
define(`MULTIPOP',
`//popping $1 items from the stack'
`forloop(`i',1,$1,`inc d
')dnl'
)dnl
