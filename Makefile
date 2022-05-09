CXX=g++
CXXFLAGS=-Wall -I include
LDFLAGS= -Llib -lsfml-graphics -lsfml-window -lsfml-system
EXEC_FILES= Final-main bin/SDL Test


all: Final-main
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

Final-main: Population.o Jeux.o Coord.o Animal.o Ensemble.o Grille.o main.o
	$(CXX) -o $@ $^ $(LDFLAGS)
	./Final-main.exe
Test : Population.o Jeux.o Coord.o Animal.o Ensemble.o Grille.o Test.o
	$(CXX) -o $@ $^ $(LDFLAGS)
	./Test
SDL :SDL.o
	g++ SDL.cpp -o bin/SDL -I include -Llib -lsfml-window -lsfml-graphics -lsfml-system
	./bin/SDL.exe




check : Test
clean :
	rm -f *.o *.ppm *.exe bin/.exe $(EXEC_FILES)