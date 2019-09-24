all: sfml-game

sfml-game:  main.o board.o game.o puck.o paddle.o
	g++ main.o board.o game.o puck.o paddle.o -o sfml-game -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp game.hpp
	g++ -c -Wall -std=gnu++11 main.cpp game.hpp

game.o: game.cpp game.hpp
	g++ -c -Wall -std=gnu++11 game.cpp game.hpp

board.o: board.cpp board.hpp 
	g++ -c -Wall -std=gnu++11 board.cpp board.hpp
	
puck.o: puck.cpp puck.hpp
	g++ -c -Wall -std=gnu++11 puck.cpp puck.hpp
	
paddle.o: paddle.cpp paddle.hpp
	g++ -c -Wall -std=gnu++11 paddle.cpp paddle.hpp	
    
clean:
	rm *.o *.hpp.gch sfml-game
