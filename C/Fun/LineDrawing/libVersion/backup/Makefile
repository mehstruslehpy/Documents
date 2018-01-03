CC= gcc 
LIB= -lm -lncurses -ltinfo
FLAG= -Wall -Wextra -pedantic -fPIC 
RULES= NLine NQuad NSine NCircle NElli NLSeg NLSqr NLTri NLRect 
OBJ= NLine.o NQuad.o NSine.o NCircle.o NElli.o NLSeg.o NLSqr.o NLTri.o NLRect.o

#build as a single program (mainly for testing)
MAIN-PROG: Shapes.c $(RULES)	
	$(CC) $(LIB) $(FLAG) $(OBJ) Shapes.c -o Shapes.o 

#build as an archived library
MAIN-LIB: $(RULES)	
	ar -cvq libShapes.a $(OBJ)

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

clean:
	rm $(OBJ) Shapes.o *.a *.orig
