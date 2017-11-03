frac:	main.o Jugador.o
	g++ -std=c++11 main.o Jugador.o -lncurses
main.o:	main.cpp
	g++ -c main.cpp
Jugador.o:	Jugador.cpp
	g++ -c Jugador.cpp
