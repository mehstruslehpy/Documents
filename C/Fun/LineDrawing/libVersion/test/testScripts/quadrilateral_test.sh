#!/bin/sh 
A=$(( ( RANDOM % 40 )  + 1 ))
B=$(( ( RANDOM % 40 )  + 1 ))
C=$(( ( RANDOM % 40 )  + 1 ))
D=$(( ( RANDOM % 40 )  + 1 ))
E=$(( ( RANDOM % 40 )  + 1 ))
F=$(( ( RANDOM % 40 )  + 1 ))
G=$(( ( RANDOM % 40 )  + 1 ))
H=$(( ( RANDOM % 40 )  + 1 ))
echo $A $B $C $D $E $F $G $H
../testObjects/DrawQuadrilateral.o $A $B $C $D $E $F $G $H
