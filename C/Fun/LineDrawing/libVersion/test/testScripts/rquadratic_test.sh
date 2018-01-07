#!/bin/sh 
A=$(./randFloat.sh)
B=$(./randFloat.sh)
C=$(./randFloat.sh)
# to get a random num in the range [a,b] do $((RANDOM % (b-a+1) + a))
D=$((RANDOM % (0-(-90)+1) + (-90)))

echo $A $B $C 0 0 $D
../testObjects/DrawRQuadratic.o $A $B $C 0 0 $D
