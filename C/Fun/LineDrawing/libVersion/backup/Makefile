CC= gcc 
LIB= -lm -lncurses -ltinfo
FLAG= -Wall -Wextra -pedantic -fPIC 
RULES= NLine NQuad NSine NCircle NElli NLSeg NLSqr NLTri NLRect Misc 
OBJ= NLine.o NQuad.o NSine.o NCircle.o NElli.o NLSeg.o NLSqr.o NLTri.o NLRect.o Misc.o

#build as a single program (mainly for testing)
MAIN-PROG: Shapes.c $(RULES)	
	$(CC) $(LIB) $(FLAG) $(OBJ) Shapes.c -o Shapes.o 

#build as an archived library
library: $(RULES)	
	ar -cvq libShapes.a $(OBJ)

#build test programs
test: $(RULES)
	$(CC) $(LIB) $(FLAG) -g -pg test/CircleTest.c Misc.o NCircle.o -o test/DrawCircle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/EllipseTest.c Misc.o NElli.o -o test/DrawEllipse.o
	$(CC) $(LIB) $(FLAG) -g -pg test/LineSegmentTest.c Misc.o NLSeg.o -o test/DrawLineSegment.o
	$(CC) $(LIB) $(FLAG) -g -pg test/LineTest.c Misc.o NLine.o -o test/DrawLine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/QuadraticTest.c Misc.o NQuad.o -o test/DrawQuadratic.o
	$(CC) $(LIB) $(FLAG) -g -pg test/RectangleTest.c Misc.o NLSeg.o NLRect.o -o test/DrawRectangle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/SineTest.c Misc.o NSine.o -o test/DrawSine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/SquareTest.c Misc.o NLSeg.o NLSqr.o -o test/DrawSquare.o
	$(CC) $(LIB) $(FLAG) -g -pg test/TriangleTest.c Misc.o NLSeg.o NLTri.o -o test/DrawTriangle.o

#build the object files
NLine: NLine.c
	$(CC) $(LIB) $(FLAG) NLine.c -o NLine.o -c
NQuad: NQuad.c
	$(CC) $(LIB) $(FLAG) NQuad.c -o NQuad.o -c
NSine: NSine.c
	$(CC) $(LIB) $(FLAG) NSine.c -o NSine.o -c
NCircle: NCircle.c
	$(CC) $(LIB) $(FLAG) NCircle.c -o NCircle.o -c
NElli: NElli.c
	$(CC) $(LIB) $(FLAG) NElli.c -o NElli.o -c
NLSeg: NLSeg.c
	$(CC) $(LIB) $(FLAG) NLSeg.c -o NLSeg.o -c
NLSqr: NLSeg NLSqr.c
	$(CC) $(LIB) $(FLAG) NLSqr.c -o NLSqr.o -c
NLTri: NLSeg NLTri.c
	$(CC) $(LIB) $(FLAG) NLTri.c -o NLTri.o -c
NLRect: NLSeg NLRect.c
	$(CC) $(LIB) $(FLAG) NLRect.c -o NLRect.o -c
Misc: Misc.c
	$(CC) $(LIB) $(FLAG) Misc.c -o Misc.o -c
	
clean:
	astyle *.c *.h
	rm $(OBJ) Shapes.o *.a *.orig
	rm ./test/*.o ./test/*.orig ./test/*.out
