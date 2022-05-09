#ifndef PROJETRENARDLAPIN_COORD_HPP
#define PROJETRENARDLAPIN_COORD_HPP
#include <iostream>
#include "Ensemble.hpp"
using namespace std;
const int TAILLE  = 100;
struct Coord {
    Coord(int );
    Coord(int , int);
    bool operator==(Coord )const ;
    bool operator!=(Coord other) const{ return not (*this == other) ;}
    int getX() const{ return x; }
    int getY() const { return y ;}
    Coord getCoord() const {return *this;}
    int toInt() const;
    Ensemble voisines() const;
    friend std::ostream& operator<<(std::ostream& , Coord);

private :
    int x , y;
};

#endif //PROJETRENARDLAPIN_COORD_HPP