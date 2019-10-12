battleship: main.o board.o battleExec.o HumanPlayer.o AI.o
	g++ -std=c++11 -g -Wall main.o board.o battleExec.o HumanPlayer.o AI.o -o battleship

main.o: main.cpp board.h battleExec.h
	g++ -std=c++11 -g -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -std=c++11 -g -Wall -c board.cpp

battleExec.o: battleExec.h battleExec.cpp
	g++ -std=c++11 -g -Wall -c battleExec.cpp

HumanPlayer.o: HumanPlayer.h HumanPlayer.cpp PlayerInterface.h board.h
	g++ -std=c++11 -g -Wall -c HumanPlayer.cpp

AI.o: AI.h AI.cpp PlayerInterface.h board.h
	g++ -std=c++11 -g -Wall -c AI.cpp

clean:
	rm *.o battleship
