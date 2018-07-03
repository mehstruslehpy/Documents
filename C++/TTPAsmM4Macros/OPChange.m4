dnl is used as the default m4 comment delimiter
dnl after an m4 command will suppress its output
dnl MACOP(x,y,op) is a macro that emits ttpasm
define(`MACOP',`ldi a, $1
ldi b, $2
$3 a,b
')dnl
dnl emit code from the MACADD macro several times
dnl with different arguments
