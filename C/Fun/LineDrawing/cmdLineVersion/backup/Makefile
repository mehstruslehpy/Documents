CC=gcc 
LIB=-lm -lncurses -ltinfo
FLAG= -Wall -pedantic

MAIN: NLine NQuad NSine NCircle NElli NLSeg DrawFace NLSqr NLTri NLRect NLQuadrilateral
NLine: NLine.c
	$(CC) $(LIB) $(FLAG) NLine.c -o NLine.o
NQuad: NQuad.c
	$(CC) $(LIB) $(FLAG) NQuad.c -o NQuad.o
NSine: NSine.c
	$(CC) $(LIB) $(FLAG) NSine.c -o NSine.o
NCircle: NCircle.c
	$(CC) $(LIB) $(FLAG) NCircle.c -o NCircle.o
NElli: NElli.c
	$(CC) $(LIB) $(FLAG) NElli.c -o NElli.o
NLSeg: NLSeg.c
	$(CC) $(LIB) $(FLAG) NLSeg.c -o NLSeg.o
NLSqr: NLSeg NLSqr.c
	$(CC) $(LIB) $(FLAG) NLSqr.c -o NLSqr.o
NLTri: NLSeg NLTri.c
	$(CC) $(LIB) $(FLAG) NLTri.c -o NLTri.o
NLRect: NLSeg NLRect.c
	$(CC) $(LIB) $(FLAG) NLRect.c -o NLRect.o
NLQuadrilateral: NLSeg NLRect.c
	$(CC) $(LIB) $(FLAG) NLQuadrilateral.c -o NLQuadrilateral.o
DrawFace: NCircle
	$(CC) $(LIB) $(FLAG) DrawFace.c -o DrawFace.o

clean:
	rm *.o
