#ifndef PROJETRENARDLAPIN_COORD_HPP
#define PROJETRENARDLAPIN_COORD_HPP
#include <iostream>
#include "Ensemble.hpp"
using namespace std;
const int TAILLE  = 100;
struct Coord {
    
    //constructors
    
    Coord(int );
    Coord(int , int);
    
    //surcharge operateurs
    
    bool operator==(Coord )const ;
    bool operator!=(Coord other) const{ return not (*this == other) ;}
    
    //methodes
    
    /**
     * @brief 
     * 
     * @return l'abscisse du point
     */
    int getX() const{ return x; }
    
    /**
     * @brief 
     * 
     * @return l'ordonnee du point
     */
    int getY() const { return y ;}
    
    /**
     * @brief Get the Coord object
     * 
     * @return Coord 
     */
    Coord getCoord() const {return *this;}
    
    /**
     * @brief converti la coordonne etant en 2 dimension en une coordonne en une dimension
     * 
     * @return coordonnes en 1 dimension
     */
    int toInt() const;
    
    /**
     * @brief genere toute les coordonnes voisine a celle-ci
     * 
     * @return Ensemble contenant toute les coordonnes voisine en 1d
     */
    Ensemble voisines() const;
    
    friend std::ostream& operator<<(std::ostream& , Coord);
private :
    int x , y;
};

#endif //PROJETRENARDLAPIN_COORD_HPP
