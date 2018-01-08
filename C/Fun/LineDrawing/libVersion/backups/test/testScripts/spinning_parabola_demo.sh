#!/bin/bash
A=$(./randFloat.sh)
B=$(( ( RANDOM % 42 )  + 1 ))
C=$(( ( RANDOM % 42 )  + 1 ))
D=0
until [ $D -gt 360 ]; do
	cat <(sleep 0.02s ; echo "\n") | ../testObjects/DrawRParabola.o $A $B $C $B $C $D
	let D=D+1
done
