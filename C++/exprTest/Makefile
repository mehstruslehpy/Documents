all: main ptranslator ctranslator

main: prover.o main.cpp context.o boolexp.o varexp.o notexp.o andexp.o orexp.o condexp.o
	g++ -g -Wall -pedantic main.cpp varexp.o context.o boolexp.o notexp.o andexp.o orexp.o condexp.o prover.o -o main

context.o: context.h context.cpp
	g++ -g -Wall -pedantic context.cpp -o context.o -c
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
prover.o: prover.h prover.cpp
	g++ -g -Wall -pedantic prover.cpp -o prover.o -c

ptranslator: ./proofTranslator/translator.cpp
	g++ -g -Wall -pedantic ./proofTranslator/translator.cpp -o ./proofTranslator/translator

ctranslator: ./calcTranslator/translator.cpp
	g++ -g -Wall -pedantic ./calcTranslator/translator.cpp -o ./calcTranslator/translator

clean:
	astyle *.cpp
	astyle *.h
	astyle ./proofTranslator/*
	astyle ./calcTranslator/*
	rm proofTranslator/translator
	rm calcTranslator/translator
	rm *.o *.orig main proofTranslator/translator calcTranslator/translator
	rm -rf *.orig 
