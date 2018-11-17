#!/bin/sh 
A=$(( ( RANDOM % 40 )  + 1 ))
B=$(( ( RANDOM % 40 )  + 1 ))
C=$(( ( RANDOM % 40 )  + 1 ))
echo $A $B $C
./NLSqr.o $A $B $C
