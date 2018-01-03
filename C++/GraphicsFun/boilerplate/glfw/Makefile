sfml-app: main_glfw.o 
	g++ -lglfw main_glfw.o -o glfw-app 
main_sfml.o: main_sfml.cpp
	g++ -Wall -pedantic main_glfw.cpp -c
clean:
	rm -rf *.out glfw-app *.o core
