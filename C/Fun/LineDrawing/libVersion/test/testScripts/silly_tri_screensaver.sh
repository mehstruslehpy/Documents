#!/bin/sh
while :
do
	A=$(( ( RANDOM % 40 )  + 1 ))
	B=$(( ( RANDOM % 40 )  + 1 ))
	C=$(( ( RANDOM % 40 )  + 1 ))
	D=$(( ( RANDOM % 40 )  + 1 ))
	E=$(( ( RANDOM % 40 )  + 1 ))
	F=$(( ( RANDOM % 40 )  + 1 ))
	$(sleep 1; echo "\n")| ../testObjects/DrawTriangle.o $A $B $C $D $E $F 
done
