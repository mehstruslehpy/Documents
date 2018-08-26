all: main translator

main: prooftree.o main.cpp context.o boolexp.o varexp.o notexp.o andexp.o orexp.o condexp.o
	g++ -g -Wall -pedantic main.cpp varexp.o context.o boolexp.o notexp.o andexp.o orexp.o condexp.o prooftree.o -o main

boolexp.o: boolexp.h boolexp.cpp
	g++ -g -Wall -pedantic boolexp.cpp -o boolexp.o -c
varexp.o: varexp.h varexp.cpp
	g++ -g -Wall -pedantic varexp.cpp -o varexp.o -c
notexp.o: notexp.h notexp.cpp
	g++ -g -Wall -pedantic notexp.cpp -o notexp.o -c
andexp.o: andexp.h andexp.cpp
	g++ -g -Wall -pedantic andexp.cpp -o andexp.o -c
orexp.o: orexp.h orexp.cpp
	g++ -g -Wall -pedantic orexp.cpp -o orexp.o -c
condexp.o: condexp.h condexp.cpp
	g++ -g -Wall -pedantic condexp.cpp -o condexp.o -c
prooftree.o: prooftree.h prooftree.cpp
	g++ -g -Wall -pedantic prooftree.cpp -o prooftree.o -c

translator: ./proofTranslator/translator.cpp
	g++ -g -Wall -pedantic ./proofTranslator/translator.cpp -o ./proofTranslator/translator

clean:
	./clean.sh
