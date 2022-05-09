#ifndef PROJETRENARDLAPIN_GRILLE_HPP
#define PROJETRENARDLAPIN_GRILLE_HPP
#include "Coord.hpp"
#include <iostream>
#include <array>
using Plateau = std::array<std::array<int,TAILLE>,TAILLE>;
struct Grille {
    Grille();
    bool CaseVide(Coord ind) const{return GetId(ind) == -1;}
    int GetId(Coord ind)const {return grille[ind.getX()][ind.getY()];}
    void videCase(Coord);
    void setCase(Coord, int);
private:
    Plateau grille{};
};
#endif //PROJETRENARDLAPIN_GRILLE_HPP
