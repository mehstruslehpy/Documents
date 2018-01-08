#!/bin/bash
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
D=$(( ( RANDOM % 20 )  + 1 ))
E=$(( ( RANDOM % 20 )  + 1 ))
F=$(( ( RANDOM % 20 )  + 1 ))
G=0
echo $A $B $C $D $C $D $G 
until [ $G -gt 360 ]; do
	cat <(sleep 0.02s ; echo "\n") | ../testObjects/DrawREllipse.o $A $B $C $D $C $D $G 
	let G=G+1
done
