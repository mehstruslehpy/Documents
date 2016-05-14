###############################################################
#MAKEFILES BASICALLY SAY THE FOLLOWING
#
#	output: file1 file2
#			gcc -c $< -o $@
#Some Syntax gotchas explained:
#
#	$@ would refer to the text "output"  in the previous example
#	$< would refer to the text "file1" in the previous example
#	$^ if used would refer to the texts "file1" and "file2"
#
###############################################################

CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-lportaudio
SOURCES=RingBuf.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=RingBuf

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	    $(CC) $(CFLAGS) $< -o $@

