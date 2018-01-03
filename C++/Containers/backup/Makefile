#the main build rules
Container: CArray CStack LStack CList LList 
	g++ -pedantic -Wall -Weffc++ main.cpp carray.o lstack.o cstack.o clist.o llist.o -o main
CArray: CArray.h CArrayTests.h CArrayTests.cpp
	g++ -pedantic -Wall -Weffc++ CArrayTests.cpp -o carray.o -c
CStack: CStack.h CStackTests.h CStackTests.cpp
	g++ -pedantic -Wall -Weffc++ CStackTests.cpp -o cstack.o -c
LStack: LStack.h LStackTests.h LStackTests.cpp
	g++ -pedantic -Wall -Weffc++ LStackTests.cpp -o lstack.o -c
CList: CList.h CListTests.h CListTests.cpp
	g++ -pedantic -Wall -Weffc++ CListTests.cpp -o clist.o -c
LList: LList.h LListTests.h LListTests.cpp
	g++ -pedantic -Wall -Weffc++ LListTests.cpp -o llist.o -c

#debug build rules
debug: CArray-Debug CStack-Debug LStack-Debug CList-Debug LList-Debug
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ main.cpp carray.o lstack.o cstack.o clist.o llist.o -o main
CArray-Debug: CArray.h CArrayTests.h CArrayTests.cpp
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ ArrayTests.cpp -o carray.o -c
CStack-Debug: CStack.h CStackTests.h CStackTests.cpp
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ CStackTests.cpp -o cstack.o -c
LStack-Debug: LStack.h LStackTests.h LStackTests.cpp
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ LStackTests.cpp -o lstack.o -c
CList-Debug: CList.h CListTests.h CListTests.cpp
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ CListTests.cpp -o clist.o -c
LList-Debug: LList.h LListTests.h LListTests.cpp
	g++ -pg -g -no-pie -pedantic -Wall -Weffc++ LListTests.cpp -o llist.o -c

#auxiliary build rules
clean:
	astyle *.cpp *.h
	rm main *.o *.txt *.orig gmon.out
check:
	cppcheck --enable=all . 2> err.txt
