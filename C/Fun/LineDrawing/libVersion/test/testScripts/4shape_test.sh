#!/bin/sh 
A=$(( ( RANDOM % 25 )  + 1 ))
B=$(( ( RANDOM % 25 )  + 1 ))
C=$(( ( RANDOM % 25 )  + 1 ))
D=$(( ( RANDOM % 25 )  + 1 ))
E=$(( ( RANDOM % 25 )  + 1 ))
F=$(( ( RANDOM % 25 )  + 1 ))
G=$(( ( RANDOM % 25 )  + 1 ))
H=$(( ( RANDOM % 25 )  + 1 ))
I=$(( ( RANDOM % 25 )  + 1 ))
echo $A $B $C $D $E $F $G $H $I
../testObjects/4ShapeRotate.o $A $B $C $D $E $F $G $H $I
