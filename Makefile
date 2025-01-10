
	
main.exe: main.o Grid.o Ships.o
	g++ -std=c++20  main.o Grid.o Ships.o -o main.exe
main.o: main.cpp
	g++ -std=c++20  -c main.cpp
Grid.o: Grid.cpp
	g++ -std=c++20  -c Grid.cpp
Ships.o: Ships.cpp
	g++ -std=c++20  -c Ships.cpp
Player.o: Player.cpp
	g++ -std=c++20  -c Player.cpp
HumanPlayer.o: HumanPlayer.cpp
	g++ -std=c++20  -c HumanPlayer.cpp
AiPlayer.o: AiPlayer.cpp
	g++ -std=c++20  -c AiPlayer.cpp

clean:
	rm -f *.o