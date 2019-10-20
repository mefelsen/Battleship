battleship: main.o board.o battleExec.o HumanPlayer.o AI.o PowerUpBoard.o Inventory.o Shot.o PatternManager.o
	g++ -std=c++11 -g -Wall main.o board.o battleExec.o HumanPlayer.o AI.o PowerUpBoard.o Inventory.o Shot.o PatternManager.o -o battleship

main.o: main.cpp battleExec.h
	g++ -std=c++11 -g -Wall -c main.cpp

board.o: board.cpp board.h
	g++ -std=c++11 -g -Wall -c board.cpp

battleExec.o: battleExec.h battleExec.cpp HumanPlayer.h AI.h
	g++ -std=c++11 -g -Wall -c battleExec.cpp

HumanPlayer.o: HumanPlayer.h HumanPlayer.cpp PlayerInterface.h board.h
	g++ -std=c++11 -g -Wall -c HumanPlayer.cpp

AI.o: AI.h AI.cpp PlayerInterface.h board.h
	g++ -std=c++11 -g -Wall -c AI.cpp

PowerUpBoard.o: PowerUpBoard.h 
	g++ -std=c++11 -g -Wall -c PowerUpBoard.cpp

Inventory.o: Inventory.h 
	g++ -std=c++11 -g -Wall -c Inventory.cpp

Shot.o: Shot.h 
	g++ -std=c++11 -g -Wall -c Shot.cpp
	
PatternManager.o: PatternManager.h
	g++ -std=c++11 -g -Wall -c PatternManager.cpp

clean:
	rm *.o battleship
