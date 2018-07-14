all: main

main: main.cpp LeftRiemannSum.o RightRiemannSum.o TrapezoidRule.o MidpointRiemannSum.o SimpsonRule.o
	g++ -std=c++11 -g -Wall -pedantic main.cpp LeftRiemannSum.o RightRiemannSum.o MidpointRiemannSum.o TrapezoidRule.o SimpsonRule.o -o main

LeftRiemannSum.o: LeftRiemannSum.cpp LeftRiemannSum.h
	g++ -std=c++11 -g -Wall -pedantic LeftRiemannSum.cpp -o LeftRiemannSum.o -c
RightRiemannSum.o: RightRiemannSum.cpp RightRiemannSum.h
	g++ -std=c++11 -g -Wall -pedantic RightRiemannSum.cpp -o RightRiemannSum.o -c
MidpointRiemannSum.o: TrapezoidRule.o MidpointRiemannSum.cpp MidpointRiemannSum.h
	g++ -std=c++11 -g -Wall -pedantic MidpointRiemannSum.cpp -o MidpointRiemannSum.o -c
TrapezoidRule.o: TrapezoidRule.cpp TrapezoidRule.h
	g++ -std=c++11 -g -Wall -pedantic TrapezoidRule.cpp -o TrapezoidRule.o -c
SimpsonRule.o: TrapezoidRule.o MidpointRiemannSum.o SimpsonRule.cpp SimpsonRule.h
	g++ -std=c++11 -g -Wall -pedantic SimpsonRule.cpp -o SimpsonRule.o -c

clean:
	./clean.sh
