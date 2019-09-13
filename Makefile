battleship: main.o board.o
	g++ -std=c++11 -g -Wall main.o board.o -o battleship

main.o: main.cpp board.h
	g++ -std=c++11 -g -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -std=c++11 -g -Wall -c board.cpp

clean:
	rm *.o battleship
