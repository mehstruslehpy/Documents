#!/bin/sh
clear
read  -n 1 -p "[ --press space to continue-- ]"
./NSine.o 5 0.2 0 5
./NSine.o 10 0.1 0 10
./NSine.o 3 0.3 3 10
./NSine.o 10 0.01 0 20
./NLine.o 0 7
./NLine.o 2 10
./NQuad.o -.01 0 30
./NQuad.o 0.1 0 0
./NCircle.o 5 10 10
./NCircle.o 3 15 10
./NCircle.o 7 9 12
./NCircle.o 13 5 20
./NCircle.o 10 10 0
./NElli.o 15 8 20 15
./NElli.o 4 8 7 10
./NElli.o 12 5 20 15
./NLSeg.o 0 0 12 12
./NLSeg.o 7 7 12 12
./NLSeg.o 12 12 3 3
./NLSqr.o 5 5 1
./NLSqr.o 22 22 10
./NLTri.o 26 16 17 21 30 7
./NLTri.o 40 20 32 40 15 18
./NLTri.o 39 14 37 40 14 15
./NLTri.o 6 24 32 20 40 5
./NLRect.o 7 11 11 12
./NLRect.o 16 4 4 7 

./DrawFace.o
