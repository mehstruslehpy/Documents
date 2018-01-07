#!/bin/sh 
A=$(( ( RANDOM % 50 )  + 1 ))
B=$(( ( RANDOM % 50 )  + 1 ))
C=$(( ( RANDOM % 50 )  + 1 ))
D=$(( ( RANDOM % 50 )  + 1 ))
E=$(( ( RANDOM % 50 )  + 1 ))
F=$(( ( RANDOM % 50 )  + 1 ))
G=$(( ( RANDOM % 105 )  + 1 ))
echo $A $B $C $D $E $F
../testObjects/DrawRTriangle.o $A $B $C $D $E $F $A $B $G
