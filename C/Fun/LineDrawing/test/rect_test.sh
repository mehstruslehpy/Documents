#!/bin/sh 
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
D=$(( ( RANDOM % 20 )  + 1 ))
echo $A $B $C $D
./NLRect.o $A $B $C $D
