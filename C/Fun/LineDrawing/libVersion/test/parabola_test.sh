#!/bin/sh 
A=$(./randFloat.sh)
B=$(( ( RANDOM % 25 )  + 1 ))
C=$(( ( RANDOM % 25 )  + 1 ))
echo $A $B $C
./DrawParabola.o $A $B $C
