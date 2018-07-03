dnl RUNTIMECOUNTEDFOR(<counter-rg>,<counter-val>,<loop-tag>,<code-to-run>)
define(`RUNTIMECOUNTEDFOR',
`//m4: emitting a counted for loop
//##########################################################
//m4: load the counter value into the $1 register
ldi $1,$2

//m4: begin the loop
FOR_BEGIN_$3:

//m4: begin the loop test
//m4: store the b reg temporarily for the loop test
dec d
st (d),b
//m4: load 0 into b
ldi b,0 
//m4: compute: 0-a for comparison
cmp b,a
//m4: restore the b register and stk
ld b, (d)
inc d
//m4: if $2-a==0 the loop is over 
//m4: if not keep looping
jzi FOR_END_$3
jmpi FOR_CONTINUE_$3

FOR_CONTINUE_$3:
//m4: begin user code
$4
//m4: end user code
//m4: increment the counter
dec a
//m4: jump to start of loop
jmpi FOR_BEGIN_$3

//m4: end of the loop
FOR_END_$3:
//##########################################################'
)dnl
