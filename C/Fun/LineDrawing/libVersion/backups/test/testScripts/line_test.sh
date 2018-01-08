#!/bin/sh 
#this is not a very good test
A=$(./randFloat.sh)
B=$(( ( RANDOM % 40 )  + 1 ))
echo $A $B 
../testObjects/DrawLine.o $A $B
