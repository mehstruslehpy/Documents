#!/bin/sh 
A=$(( ( RANDOM % 10 )  + 1 ))
B=$(./randFloat.sh % 10)
C=$(( ( RANDOM % 25 )  + 1 ))
D=$(( ( RANDOM % 15 )  + 1 ))
echo $A $B $C $D
../testObjects/DrawCosecant.o $A $B $C $D
