all: main

main: main.cpp ./RegBank/RegBank.o ./Ram/Ram.o ./IO/IO.o CompSim.o 
	g++ -pg -Wall -pedantic main.cpp CompSim.o ./RegBank/RegBank.o ./Ram/Ram.o ./IO/IO.o -o main

CompSim.o: CompSim.h CompSim.cpp Instructions.cpp
	g++ -pg -Wall -pedantic CompSim.cpp -o CompSim.o -c
./RegBank/RegBank.o: ./RegBank/RegBank.h ./RegBank/RegBank.cpp
	g++ -pg -Wall -pedantic ./RegBank/RegBank.cpp -o ./RegBank/RegBank.o -c
./Ram/Ram.o: ./Ram/Ram.h ./Ram/Ram.cpp
	g++ -pg -Wall -pedantic ./Ram/Ram.cpp -o ./Ram/Ram.o -c
./IO/IO.o: ./IO/IO.h ./IO/IO.cpp
	g++ -pg -Wall -pedantic ./IO/IO.cpp -o ./IO/IO.o -c

clean:
	./clean.sh
