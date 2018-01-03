sfml-app: main_sdl.o 
	g++ -lSDL2 main_sdl.o -o sdl-app
main_sfml.o: main_sdl.cpp
	g++ -Wall -pedantic main_sdl.cpp -I/usr/include/SDL2 -c
clean:
	rm -rf *.o *.out core sdl-app
