main: main.o level.o environment.o
	g++ -g3 main.o level.o environment.o -o main -lSDL
main.o:  main.cpp level.h 
	g++ -g3 -c main.cpp	-o main.o
level.o: level.cpp level.h environment.h
	g++ -g3 -c level.cpp -o level.o
environment.o: 	environment.cpp environment.h
	g++ -g3 -c environment.cpp -o environment.o
