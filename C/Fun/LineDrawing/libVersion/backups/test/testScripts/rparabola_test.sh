#!/bin/sh 
A=$(./randFloat.sh)
B=$(( ( RANDOM % 42 )  + 1 ))
C=$(( ( RANDOM % 42 )  + 1 ))
D=$(( ( RANDOM % 105 )  + 1 ))
echo $A $B $C $A $B $D
../testObjects/DrawRParabola.o $A $B $C $B $C $D
