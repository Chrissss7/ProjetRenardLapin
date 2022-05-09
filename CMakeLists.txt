cmake_minimum_required(VERSION 3.20)
project(ProjetRenardLapin)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjetRenardLapin SFML main.cpp Animal.cpp Population.cpp Coord.cpp Jeux.cpp Grille.cpp  Ensemble.cpp Test.cpp SDL.cpp)
