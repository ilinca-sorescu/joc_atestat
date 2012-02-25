INCLUDE= -I/opt/local/include
LIB_DIR= -L/opt/local/lib
LIBS= -lSDL

main: main.o level.o environment.o animation.o character.o player.o
	g++ -g3 main.o level.o environment.o animation.o character.o player.o -o main $(LIB_DIR) $(LIBS)
main.o:  main.cpp level.h 
	g++ $(INCLUDE) -g3 -c main.cpp	-o main.o
level.o: level.cpp level.h environment.h player.h
	g++ $(INCLUDE) -g3 -c level.cpp -o level.o
environment.o: 	environment.cpp environment.h
	g++ $(INCLUDE) -g3 -c environment.cpp -o environment.o
animation.o: animation.cpp animation.h		
	g++ $(INCLUDE) -g3 -c animation.cpp -o animation.o
character.o: character.cpp character.h animation.h	
	g++ $(INCLUDE) -g3 -c character.cpp -o character.o
player.o: player.cpp player.h character.h	
	g++ $(INCLUDE) -g3 -c player.cpp -o player.o
