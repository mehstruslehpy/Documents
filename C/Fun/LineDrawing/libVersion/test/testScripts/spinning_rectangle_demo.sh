#!/bin/bash 
A=$(( ( RANDOM % 20 )  + 1 ))
B=$(( ( RANDOM % 20 )  + 1 ))
C=$(( ( RANDOM % 20 )  + 1 ))
D=$(( ( RANDOM % 20 )  + 1 ))
E=0
echo $A $B $C $D $A $B $E
until [ $E -gt 360 ]; do
	cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRRectangle.o $A $B $C $D $A $B $E
	let E=E+1
done
