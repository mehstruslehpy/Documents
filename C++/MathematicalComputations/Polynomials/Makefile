all: main

main: main.cpp ArrayRepPoly.o 
	g++ -std=c++11 -g -Wall -pedantic main.cpp ArrayRepPoly.o -o main

ArrayRepPoly.o: ArrayRepPoly.cpp ArrayRepPoly.h
	g++ -std=c++11 -g -Wall -pedantic ArrayRepPoly.cpp -o ArrayRepPoly.o -c

clean:
	./clean.sh
