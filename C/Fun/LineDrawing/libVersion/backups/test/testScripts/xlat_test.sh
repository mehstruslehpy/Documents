#!/bin/sh 
A=$(( ( RANDOM % 5 )  + 1 ))
B=$(( ( RANDOM % 5 )  + 1 ))
C=$(( ( RANDOM % 5 )  + 1 ))
D=$(( ( RANDOM % 5 )  + 1 ))
echo $A $B $C $D 
../testObjects/XlatTest.o $A $B $C $D 
