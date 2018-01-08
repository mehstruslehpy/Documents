#!/bin/bash
#clear
#generic demo bits
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

##c program animations
clear
./4shape_test.sh
clear
./fan_rotate_test.sh
clear

#scripted animations
read  -n 1 -p "[ --Ctrl-c to quit or enter for more moving demos-- ]"
#./all_random_spinning_demos.sh
#ellipse 5 7 7 17 7 17 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawREllipse.o 5 7 7 17 7 17 $X
	let X=X+1
done

#quadrilateral 2 15 11 5 3 18 17 11 10 12 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRQuadrilateral.o 2 15 11 5 3 18 17 11 10 12 $X
	let X=X+1
done

#rectangle 10 5 11 20 10 5 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRRectangle.o 10 5 11 20 10 5 $X
	let X=X+1
done

#triangle 47 15 1 17 50 45 47 15 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRTriangle.o 47 15 1 17 50 45 47 15 $X
	let X=X+1
done

#cosecant 4 1.59233 10 3 0 0 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRCosecant.o 4 0.29233 10 3 0 0 $X
	let X=X+1
done

#cosine 12 .09995 22 14 0 0 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRCosine.o 12 .09995 22 14 0 0 $X
	let X=X+1
done

#parabola .73891 31 25 31 25 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRParabola.o 0.73891 31 25 31 25 $X
	let X=X+1
done

#sine 6 .37470 16 11 0 0 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRSine.o 6 .37470 16 11 0 0 $X
	let X=X+1
done

#tangent 6 1.47691 8 2 0 0 0
clear
X=0
until [ $X -gt 360 ]; do
    cat <(sleep 0.02s; echo "\n") | ../testObjects/DrawRTan.o 6 1.47691 8 2 0 0 $X
	let X=X+1
done

#read  -n 1 -p "[ --Ctrl-c to quit or enter for more randomized moving demos-- ]"
#./all_random_spinning_demos.sh
clear
