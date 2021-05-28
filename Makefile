CC = g++
CFLAGS = -g -std=c++11

output: hunt_the_wumpus.o event.o wumpus.o bats.o pit.o gold.o escape.o room.o adventurer.o game.o
	$(CC) $(CFLAGS) hunt_the_wumpus.o event.o wumpus.o bats.o pit.o gold.o escape.o room.o adventurer.o game.o -o output

hunt_the_wumpus.o: hunt_the_wumpus.cpp common.hpp
	$(CC) $(CFLAGS) -c hunt_the_wumpus.cpp

event.o: event.cpp event.h
	$(CC) $(CFLAGS) -c event.cpp

wumpus.o: wumpus.cpp wumpus.h 
	$(CC) $(CFLAGS) -c wumpus.cpp

bats.o: bats.cpp bats.h
	$(CC) $(CFLAGS) -c bats.cpp

pit.o: pit.cpp pit.h 
	$(CC) $(CFLAGS) -c pit.cpp

gold.o: gold.cpp gold.h 
	$(CC) $(CFLAGS) -c gold.cpp

escape.o: escape.cpp escape.h 
	$(CC) $(CFLAGS) -c escape.cpp

room.o: room.cpp room.h 
	$(CC) $(CFLAGS) -c room.cpp

adventurer.o: adventurer.cpp adventurer.h common.hpp
	$(CC) $(CFLAGS) -c adventurer.cpp

game.o: game.cpp game.h common.hpp
	$(CC) $(CFLAGS) -c game.cpp

clean:
	rm *.o output assign4.tar

assign4.tar: Makefile *.cpp *.h 
	tar -cvf assign4.tar *cpp *.h *.hpp Makefile