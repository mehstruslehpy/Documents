The macro version of the output program is an interesting example in that it hides a lot of the ugly boring stuff
in macros which get expanded inline

The DumbClock.sh script uses the linux command date to pass formatted data to clock.o in a loop

Examples: ./clock.o $(date +%H%M)  							prints the current hour and minute
		  ./output_macros 0 1 2 3 4 5 6 7 8 9 : 			prints all displayable digits
