#!/bin/sh 
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
D=$(( ( RANDOM % 20 )  + 1 ))
E=$(( ( RANDOM % 20 )  + 1 ))
F=$(( ( RANDOM % 20 )  + 1 ))
G=$(( ( RANDOM % 20 )  + 1 ))
H=$(( ( RANDOM % 20 )  + 1 ))

echo $A $B $C $D $E $F $G $H
./NLQuadrilateral.o $A $B $C $D $E $F $G $H