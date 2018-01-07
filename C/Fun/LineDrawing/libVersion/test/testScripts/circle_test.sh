#!/bin/sh 
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
echo $A $B $C 
../testObjects/DrawCircle.o $A $B $C 
