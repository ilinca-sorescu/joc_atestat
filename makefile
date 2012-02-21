main: main.o level.o environment.o
	g++ main.o level.o environment.o -o main -lSDL
main.o:  main.cpp level.h 
	g++ -c main.cpp	-o main.o
level.o: level.cpp level.h environment.h
	g++ -c level.cpp -o level.o
environment.o: 	environment.cpp environment.h
	g++ -c environment.cpp -o environment.o
