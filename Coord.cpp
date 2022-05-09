#include "Coord.hpp"
Coord::Coord(int i) {
    if (i >= TAILLE * TAILLE)
        throw std::invalid_argument("Index non valide");
    x = i / TAILLE;
    y = i % TAILLE;
}
int Coord::toInt() const {
    return x * TAILLE + y;
}
Coord::Coord(int x, int y) : x{x},  y{y}{
    if(x > TAILLE or y > TAILLE or x < 0 or y < 0)
        throw std::invalid_argument("Cannot initialize coord to this value");
};
bool Coord::operator==(Coord other) const {
    return x == other.x and y == other.y;
}
std::ostream& operator<<(std::ostream& out , Coord a){
    out << "(" << a.x << "," <<a.y << ")";
    return out;
}
Ensemble Coord::voisines() const {
    Ensemble v = Ensemble();
    for(int i = max(0,x-1) ; i <= min(TAILLE-1,x+1) ; i ++){
        for(int j = max(0,y-1) ; j <= min(TAILLE-1,y+1) ; j++){
            if(Coord(i,j) != *this){
                v.ajoute(Coord(i,j).toInt());
            }
        }
    }
    return v;
}