main: main.cpp context.o boolexp.o varexp.o notexp.o andexp.o orexp.o
	g++ -pedantic main.cpp varexp.o context.o boolexp.o notexp.o andexp.o orexp.o -o main

context.o: context.h context.cpp
	g++ -pedantic context.cpp -o context.o -c
boolexp.o: boolexp.h boolexp.cpp
	g++ -pedantic boolexp.cpp -o boolexp.o -c
varexp.o: varexp.h varexp.cpp
	g++ -pedantic varexp.cpp -o varexp.o -c
notexp.o: notexp.h notexp.cpp
	g++ -pedantic notexp.cpp -o notexp.o -c
andexp.o: andexp.h andexp.cpp
	g++ -pedantic andexp.cpp -o andexp.o -c
orexp.o: orexp.h orexp.cpp
	g++ -pedantic orexp.cpp -o orexp.o -c

#todo:
#condexp.o:
#prover.o:

clean:
	astyle *.cpp
	astyle *.h
	rm *.o *.orig main
