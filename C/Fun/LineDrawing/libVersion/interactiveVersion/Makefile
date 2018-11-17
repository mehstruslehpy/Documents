CC=gcc 
LIB=-lm -lncurses -ltinfo

MAIN: NLine NQuad NSine

NLine: NLine.c
	$(CC) $(LIB) NLine.c -o NLine.o
NQuad: NQuad.c
	$(CC) $(LIB) NQuad.c -o NQuad.o
NSine: NSine.c
	$(CC) $(LIB) NSine.c -o NSine.o

clean:
	rm *.o
