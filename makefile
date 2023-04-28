main.o: main.cpp hangmangame.h Stonegame.h 128functions.h guessnumber.h matchnum.h choice.h
	g++ -c main.cpp


128functions.o: 128functions.cpp 128functions.h
	g++ -c 128functions.cpp

Stonegame.o: Stonegame.cpp Stonegame.h
	g++ -c Stonegame.cpp

choice.o: choice.cpp choice.h
	g++ -c choice.cpp

guessnumber.o: guessnumber.cpp guessnumber.h
	g++ -c guessnumber.cpp

hangmangame.o: hangmangame.cpp hangmangame.h
	g++ -c hangmangame.cpp

matchnum.o: matchnum.cpp matchnum.h
	g++ -c matchnum.cpp

main: main.o Stonegame.o choice.o guessnumber.o hangmangame.o matchnum.o 128functions.o 
	g++  -g main.o Stonegame.o choice.o 128functions.o guessnumber.o hangmangame.o matchnum.o -o main -lpthread

clean:
	rm -f main.o Stonegame.o choice.o 128functions.o guessnumber.o hangmangame.o matchnum.o main

.PHONY: clean
