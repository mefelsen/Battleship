battleship: main.o board.o battleExec.o
	g++ -std=c++11 -g -Wall main.o board.o battleExec.o -o battleship

main.o: main.cpp board.h battleExec.h
	g++ -std=c++11 -g -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -std=c++11 -g -Wall -c board.cpp

battleExec.o: battleExec.h battleExec.cpp
	g++ -std=c++11 -g -Wall -c battleExec.cpp

clean:
	rm *.o battleship
