#!/bin/bash 
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
D=$(( ( RANDOM % 20 )  + 1 ))
E=$(( ( RANDOM % 20 )  + 1 ))
F=$(( ( RANDOM % 20 )  + 1 ))
G=$(( ( RANDOM % 20 )  + 1 ))
H=$(( ( RANDOM % 20 )  + 1 ))
I=$(( ( RANDOM % 20 )  + 1 ))
J=$(( ( RANDOM % 20 )  + 1 ))
K=0
echo $A $B $C $D $E $F $G $H $I $J $K
until [ $K -gt 360 ]; do
	cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRQuadrilateral.o $A $B $C $D $E $F $G $H $I $J $K
	let K=K+1
done
