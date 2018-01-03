#!/bin/sh 
A=$(( ( RANDOM % 50 )  + 1 ))
B=$(( ( RANDOM % 50 )  + 1 ))
C=$(( ( RANDOM % 50 )  + 1 ))
D=$(( ( RANDOM % 50 )  + 1 ))
echo $A $B $C $D
./NLSeg.o $A $B $C $D
