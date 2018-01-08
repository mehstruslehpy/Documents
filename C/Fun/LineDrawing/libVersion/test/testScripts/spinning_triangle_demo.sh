#!/bin/bash 
A=$(( ( RANDOM % 50 )  + 1 ))
B=$(( ( RANDOM % 50 )  + 1 ))
C=$(( ( RANDOM % 50 )  + 1 ))
D=$(( ( RANDOM % 50 )  + 1 ))
E=$(( ( RANDOM % 50 )  + 1 ))
F=$(( ( RANDOM % 50 )  + 1 ))
G=0
echo $A $B $C $D $E $F $A $B $G
until [ $G -gt 360 ]; do
	cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRTriangle.o $A $B $C $D $E $F $A $B $G
	let G=G+1
done
