
output: hunt_the_wumpus.o event.o wumpus.o bats.o pit.o gold.o escape.o room.o adventurer.o game.o
	g++ hunt_the_wumpus.o event.o wumpus.o bats.o pit.o gold.o escape.o room.o adventurer.o game.o -o output

hunt_the_wumpus.o: hunt_the_wumpus.cpp
	g++ -c hunt_the_wumpus.cpp

event.o: event.cpp event.h
	g++ -c event.cpp

wumpus.o: wumpus.cpp wumpus.h 
	g++ -c wumpus.cpp

bats.o: bats.cpp bats.h
	g++ -c bats.cpp

pit.o: pit.cpp pit.h 
	g++ -c pit.cpp

gold.o: gold.cpp gold.h 
	g++ -c gold.cpp

escape.o: escape.cpp escape.h 
	g++ -c escape.cpp

room.o: room.cpp room.h 
	g++ -c room.cpp

adventurer.o: adventurer.cpp adventurer.h
	g++ -c adventurer.cpp

game.o: game.cpp game.h 
	g++ -c game.cpp

clean:
	rm *.o output assign4.tar

assign4.tar: Makefile *.cpp *.h 
	tar -cvf assign4.tar *cpp *.h Makefile