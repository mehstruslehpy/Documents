#!/bin/sh 
A=$(./randFloat.sh)
B=$(./randFloat.sh)
C=$(./randFloat.sh)
echo $A $B $C
./DrawQuadratic.o $A $B $C
