dnl is used as the default m4 comment delimiter
dnl after an m4 command will suppress its output
dnl MACADD(x,y) is a macro that emits ttpasm

define(`MACADD',`//compute a=$1+$2 and continue
ldi a, $1
ldi b, $2
add a,b'
)dnl
dnl emit code from the MACADD macro several times
dnl with different arguments
