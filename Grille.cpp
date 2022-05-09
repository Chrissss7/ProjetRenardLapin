#include "Grille.hpp"
void Grille::setCase(Coord ind, int val) {
    grille[ind.getX()][ind.getY()] = val;
}

void Grille::videCase(Coord a ) {
    setCase(a,-1);
}
Grille::Grille() {
    for(int i = 0; i < TAILLE * TAILLE; i ++)
        setCase(Coord(i),-1);
}