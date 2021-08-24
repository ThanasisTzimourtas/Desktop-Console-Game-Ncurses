output: main.o Moving.o Engine.o Hero.o  Gnome.o Troll.o HiScore.o
	g++ main.o Moving.o Engine.o Hero.o  Gnome.o Troll.o HiScore.o -o output -lncurses

main.o: main.cpp
	g++ -c main.cpp

Moving.o: Moving.cpp Moving.h
	g++ -c Moving.cpp

Engine.o: Engine.cpp Engine.h
	g++ -c Engine.cpp

Hero.o: Hero.cpp Hero.h
	g++ -c Hero.cpp

Gnome.o: Gnome.cpp Gnome.h
	g++ -c Gnome.cpp

Troll.o: Troll.cpp Troll.h
	g++ -c Troll.cpp

HiScore.o: HiScore.cpp HiScore.h
	g++ -c HiScore.cpp

clean:
	rm *.o output
