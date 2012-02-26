main: main.o level.o environment.o animation.o character.o player.o
	g++ -g3 main.o level.o environment.o animation.o character.o player.o -o main -lSDL -lSDL_image
main.o:  main.cpp level.h 
	g++ -g3 -c main.cpp	-o main.o
level.o: level.cpp level.h environment.h player.h
	g++ -g3 -c level.cpp -o level.o
environment.o: 	environment.cpp environment.h
	g++ -g3 -c environment.cpp -o environment.o
animation.o: animation.cpp animation.h		
	g++ -g3 -c animation.cpp -o animation.o
character.o: character.cpp character.h animation.h	
	g++ -g3 -c character.cpp -o character.o
player.o: player.cpp player.h character.h environment.h	
	g++ -g3 -c player.cpp -o player.o
