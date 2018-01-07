#!/bin/sh 
#this is not a very good test
# to get a random num in the range [a,b] do $((RANDOM % (b-a+1) + a))
A=$((RANDOM % (2-(-2)+1) + (-2)))
B=$(( ( RANDOM % 40 )  + 1 ))
echo $A $B 
../testObjects/DrawLine.o $A $B
