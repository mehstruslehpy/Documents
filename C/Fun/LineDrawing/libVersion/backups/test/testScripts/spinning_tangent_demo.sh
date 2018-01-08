#!/bin/bash 
A=$(( ( RANDOM % 10 )  + 1 ))
B=$(./randFloat.sh % 10)
C=$(( ( RANDOM % 25 )  + 1 ))
D=$(( ( RANDOM % 15 )  + 1 ))
E=0
until [ $E -gt 360 ]; do
	cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRTan.o $A $B $C $D 0 0 $E
	let E=E+1
done
