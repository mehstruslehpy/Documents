#!/bin/sh 
A=$(( ( RANDOM % 40 )  + 1 ))
B=$(( ( RANDOM % 40 )  + 1 ))
C=$(( ( RANDOM % 40 )  + 1 ))
D=$(( ( RANDOM % 40 )  + 1 ))
echo $A $B $C $D
../testObjects/MidpointTest.o $A $B $C $D
