CC= gcc
LIB= -lm -lncurses -ltinfo
FLAG= -Wall -Wextra -pedantic -fPIC
RULES= NLine NQuad NSine NCos NTan NCsc NCircle NElli NLSeg NLSqr NLTri NLRect Misc NLQuad
OBJ= NLine.o NQuad.o NSine.o NCos.o NTan.o NCsc.o NCircle.o NElli.o NLSeg.o NLSqr.o NLTri.o NLRect.o Misc.o NLQuad.o

#build as a single program
main-prog: Shapes.c $(RULES)
	$(CC) $(LIB) $(FLAG) $(OBJ) Shapes.c -o Shapes.o

#build as an archived library
library: main-prog
	ar -cvq libShapes.a $(OBJ)

#build the docs
doc: mainpage.dox Doxyfile
	doxygen Doxyfile

#build the object files
NLine: NLine.c
	$(CC) $(LIB) $(FLAG) NLine.c -o NLine.o -c
NQuad: NQuad.c
	$(CC) $(LIB) $(FLAG) NQuad.c -o NQuad.o -c
NSine: NSine.c
	$(CC) $(LIB) $(FLAG) NSine.c -o NSine.o -c
NCos: NCos.c
	$(CC) $(LIB) $(FLAG) NCos.c -o NCos.o -c
NTan: NTan.c
	$(CC) $(LIB) $(FLAG) NTan.c -o NTan.o -c
NCsc: NCsc.c
	$(CC) $(LIB) $(FLAG) NCsc.c -o NCsc.o -c
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
NLQuad: NLQuad.c
	$(CC) $(LIB) $(FLAG) NLQuad.c -o NLQuad.o -c

#clean any old object files format any C program files
clean:
	rm -rf latex/
	rm -rf html/
	test/clean.sh
	astyle *.c *.h
	rm $(OBJ) Shapes.o *.a *.orig

#build the test objects this is not meant to be super clean and streamlined
test: main-prog
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/CircleTest.c Misc.o NCircle.o -o test/testObjects/DrawCircle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/EllipseTest.c Misc.o NElli.o -o test/testObjects/DrawEllipse.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/REllipseTest.c Misc.o NElli.o -o test/testObjects/DrawREllipse.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/LineSegmentTest.c Misc.o NLSeg.o -o test/testObjects/DrawLineSegment.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/LineTest.c Misc.o NLine.o -o test/testObjects/DrawLine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/QuadraticTest.c Misc.o NQuad.o -o test/testObjects/DrawQuadratic.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RQuadraticTest.c Misc.o NQuad.o -o test/testObjects/DrawRQuadratic.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/ParabolaTest.c Misc.o NQuad.o -o test/testObjects/DrawParabola.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RParabolaTest.c Misc.o NQuad.o -o test/testObjects/DrawRParabola.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RectangleTest.c Misc.o NLSeg.o NLRect.o -o test/testObjects/DrawRectangle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RRectangleTest.c Misc.o NLSeg.o NLRect.o -o test/testObjects/DrawRRectangle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/SineTest.c Misc.o NSine.o -o test/testObjects/DrawSine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RSineTest.c Misc.o NSine.o -o test/testObjects/DrawRSine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/CosineTest.c Misc.o NCos.o NSine.o -o test/testObjects/DrawCosine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RCosineTest.c Misc.o NCos.o NSine.o -o test/testObjects/DrawRCosine.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/TanTest.c Misc.o NTan.o -o test/testObjects/DrawTan.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RTanTest.c Misc.o NTan.o -o test/testObjects/DrawRTan.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/CosecantTest.c Misc.o NCsc.o -o test/testObjects/DrawCosecant.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RCosecantTest.c Misc.o NCsc.o -o test/testObjects/DrawRCosecant.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/SquareTest.c Misc.o NLSeg.o NLSqr.o -o test/testObjects/DrawSquare.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RSquareTest.c Misc.o NLSeg.o NLSqr.o -o test/testObjects/RDrawSquare.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/TriangleTest.c Misc.o NLSeg.o NLTri.o -o test/testObjects/DrawTriangle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RTriangleTest.c Misc.o NLSeg.o NLTri.o -o test/testObjects/DrawRTriangle.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/QuadrilateralTest.c Misc.o NLSeg.o NLQuad.o -o test/testObjects/DrawQuadrilateral.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RQuadrilateralTest.c Misc.o NLSeg.o NLQuad.o -o test/testObjects/DrawRQuadrilateral.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/MidpointTest.c Misc.o NLSeg.o -o test/testObjects/MidpointTest.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/RotateDPointTest.c Misc.o NLSeg.o -o test/testObjects/RotateDPointTest.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/FanRotate.c Misc.o NLSeg.o -o test/testObjects/FanRotate.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/4ShapeRotate.c Misc.o NLSeg.o NLQuad.o -o test/testObjects/4ShapeRotate.o
	$(CC) $(LIB) $(FLAG) -g -pg test/testSources/XlatTest.c Misc.o -o test/testObjects/XlatTest.o


