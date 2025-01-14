
OBJS = Grid.h Ships.h Player.h

run: prog
	./prog

prog: main.o Grid.o Ships.o Player.o
	g++ *.o -o prog

main.o: main.cpp $(OBJS)
	g++ -c main.cpp

Grid.o: Grid.cpp
	g++ -c Grid.cpp
Ships.o: Ships.cpp
	g++ -c Ships.cpp
Player.o: Player.cpp
	g++ -c Player.cpp

clean:
	rm -f *.o prog