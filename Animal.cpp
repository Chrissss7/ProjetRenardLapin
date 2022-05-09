#include "Animal.hpp"

Animal::Animal(animaux an, Coord a, int id) : c{a}{
    type = an;
    Id = id;
    NbDeVie = -1;
    if(Id > TAILLE * TAILLE)
        throw std::invalid_argument("Ifdsnd invalide");
    if(an == animaux::Renard)
        NbDeVie = foodinit;
    Age = 0;
    int Hasard=  rand()%2;
    genre = Genre(Hasard);
}
void Animal::SetCoord(Coord a) {
    if(a.getX() > TAILLE or a.getX() < 0 or a.getY() > TAILLE or a.getY() < 0)
        throw std::invalid_argument("Coordonne invalide");
    else
        c = a;
}

bool Animal::Reproduit(int VoisinV) const {
    if(type == animaux::Renard) {
        if (NbDeVie >= foodReprod)
            return true;
    }
    if(type == animaux::Lapin)
        if (VoisinV >= MinFreeBirthLapin)
            return true;
    return false;
}
void Animal::MangeLap() {
    NbDeVie += foodlapin;
    NbDeVie = min(NbDeVie,Maxfood);
}
void Animal::ReduitVie() {
    if(NbDeVie <= 0){
        throw invalid_argument("Peux pas");
    }
    NbDeVie--;
}
bool Animal::EraseRenard() const {
    if(NbDeVie == 0)
        return true;
    else
        return false;
}
std::ostream& operator<<(std::ostream& out , const Animal a){
    switch (a.type){
        case animaux::Renard :
            out << "R"; break;
        case animaux::Lapin :
            out << "L"; break;
        case animaux::Vide:
            out << "O";break;
        default :
            out<< "B"; break;
    }
    return out;
}
bool Animal::Vieillit() const{
    if(Age >= MaxAge)
        return true;
    return false;
}
void Animal::Veillit() {
    Age++;
}
