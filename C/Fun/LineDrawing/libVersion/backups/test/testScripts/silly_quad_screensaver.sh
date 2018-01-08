#!/bin/bash
while :
do
	A=$(( ( RANDOM % 40 )  + 1 ))
	B=$(( ( RANDOM % 40 )  + 1 ))
	C=$(( ( RANDOM % 40 )  + 1 ))
	D=$(( ( RANDOM % 40 )  + 1 ))
	E=$(( ( RANDOM % 40 )  + 1 ))
	F=$(( ( RANDOM % 40 )  + 1 ))
	G=$(( ( RANDOM % 40 )  + 1 ))
	H=$(( ( RANDOM % 40 )  + 1 ))
	cat <(sleep 1; echo "\n") | ../testObjects/DrawQuadrilateral.o $A $B $C $D $E $F $G $H
done
