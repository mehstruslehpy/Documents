#!/bin/sh
clear
read  -n 1 -p "[ --press enter to continue-- ]"
../testObjects /DrawSine.o 5 0.2 0 10
../testObjects/DrawSine.o 10 0.1 0 20
../testObjects/DrawSine.o 3 0.3 3 20
../testObjects/DrawSine.o 10 0.01 0 20
../testObjects/DrawCosecant.o 1 0.1 1 1
../testObjects/DrawCosecant.o 1 0.2 1 1
../testObjects/DrawTan.o 5 0.08099 20 4
../testObjects/DrawTan.o 5 .17346 6 6
../testObjects/DrawLine.o 0 7
../testObjects/DrawLine.o 2 10
../testObjects/DrawQuadratic.o -.01 0 30
../testObjects/DrawQuadratic.o 0.1 0 0
../testObjects/DrawCircle.o 5 10 10
../testObjects/DrawCircle.o 3 15 10
../testObjects/DrawCircle.o 7 9 12
../testObjects/DrawCircle.o 13 5 20
../testObjects/DrawCircle.o 10 10 0
../testObjects/DrawEllipse.o 15 8 20 15
../testObjects/DrawEllipse.o 4 8 7 10
../testObjects/DrawEllipse.o 12 5 20 15
../testObjects/DrawLineSegment.o 0 0 12 12
../testObjects/DrawLineSegment.o 7 7 12 12
../testObjects/DrawLineSegment.o 12 12 3 3
../testObjects/DrawSquare.o 5 5 1
../testObjects/DrawSquare.o 22 22 10
../testObjects/DrawTriangle.o 26 16 17 21 30 7
../testObjects/DrawTriangle.o 40 20 32 40 15 18
../testObjects/DrawTriangle.o 39 14 37 40 14 15
../testObjects/DrawTriangle.o 6 24 32 20 40 5
../testObjects/DrawRectangle.o 7 11 11 12
../testObjects/DrawRectangle.o 16 4 4 7 
../testObjects/DrawRSine.o 5 0.2 0 30 -15
./4shape_test.sh
./fan_rotate_test.sh
clear
read  -n 1 -p "[ --Ctrl-c to quit or enter for more randomized moving demos-- ]"
./all_spinning_demos.sh
clear
