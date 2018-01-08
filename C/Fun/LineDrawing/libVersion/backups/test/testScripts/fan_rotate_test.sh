#!/bin/sh 
A=$(( ( RANDOM % 25 )  + 1 ))
B=$(( ( RANDOM % 25 )  + 1 ))
C=$(( ( RANDOM % 25 )  + 1 ))
D=$(( ( RANDOM % 25 )  + 1 ))
E=$(( ( RANDOM % 25 )  + 1 ))
echo $A $B $C $D $E
../testObjects/FanRotate.o $A $B $C $D $E
