CXX=g++
CXXFLAGS=-Wall -I include
LDFLAGS= -Llib -lsfml-graphics -lsfml-window -lsfml-system
EXEC_FILES= bin/ppm-main bin/sfml-main Test


all: Final-main
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

ppm-main: Population.o Jeux.o Coord.o Animal.o Ensemble.o Grille.o ppm-main.o
	$(CXX) -o $@ $^ $(LDFLAGS)
	
Test : Population.o Jeux.o Coord.o Animal.o Ensemble.o Grille.o Test.o
	$(CXX) -o $@ $^ $(LDFLAGS)
	./Test
sfml-main : Population.o Jeux.o Coord.o Animal.o Ensemble.o Grille.o sfml-main.o
	g++ SDL.cpp -o bin/SDL -I include -Llib -lsfml-window -lsfml-graphics -lsfml-system
	




check : Test
clean :
	rm -f *.o *.ppm *.exe bin/.exe $(EXEC_FILES)
