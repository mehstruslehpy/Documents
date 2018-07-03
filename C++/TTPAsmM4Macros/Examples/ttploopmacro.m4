//a more fully fledged ttp example
include(RunTimeCountedForLoop.m4)dnl
//run the macro

RUNTIMECOUNTEDFOR(a,15,MYLOOPTAG,
//user: this is user code to run inside the for loop
nop
inc c
inc c
dec d
dec d
dec d
nop
//user: user code ends here
)dnl 

//halt the program
halt
