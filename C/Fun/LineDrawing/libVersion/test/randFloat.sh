#NOT MY CODE
#https://www.linuxquestions.org/questions/programming-9/random-float-numbers-in-bash-871336/
MULTIPLIER=2 # generates from 0 - 9.99999
echo "scale=5; $RANDOM*$MULTIPLIER/32767" | bc
