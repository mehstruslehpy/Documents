#!/bin/sh
clear
read  -n 1 -p "[ --press space to continue-- ]"
./DrawSine.o 5 0.2 0 10
./DrawSine.o 10 0.1 0 20
./DrawSine.o 3 0.3 3 20
./DrawSine.o 10 0.01 0 20
./DrawCosecant.o 1 0.1 1 1
./DrawCosecant.o 1 0.2 1 1
./DrawLine.o 0 7
./DrawLine.o 2 10
./DrawQuadratic.o -.01 0 30
./DrawQuadratic.o 0.1 0 0
./DrawCircle.o 5 10 10
./DrawCircle.o 3 15 10
./DrawCircle.o 7 9 12
./DrawCircle.o 13 5 20
./DrawCircle.o 10 10 0
./DrawEllipse.o 15 8 20 15
./DrawEllipse.o 4 8 7 10
./DrawEllipse.o 12 5 20 15
./DrawLineSegment.o 0 0 12 12
./DrawLineSegment.o 7 7 12 12
./DrawLineSegment.o 12 12 3 3
./DrawSquare.o 5 5 1
./DrawSquare.o 22 22 10
./DrawTriangle.o 26 16 17 21 30 7
./DrawTriangle.o 40 20 32 40 15 18
./DrawTriangle.o 39 14 37 40 14 15
./DrawTriangle.o 6 24 32 20 40 5
./DrawRectangle.o 7 11 11 12
./DrawRectangle.o 16 4 4 7 
clear
