#ifndef PROJETRENARDLAPIN_ANIMAL_HPP
#define PROJETRENARDLAPIN_ANIMAL_HPP
#include "Coord.hpp"
const int foodinit = 5;
const int foodlapin = 5;
const int Maxfood = 10;
const float ProbBirthRenard = 0.05;
const int foodReprod = 8;
const float ProbBirthLapin = 0.6    ;
const int MinFreeBirthLapin = 4;
const int MaxAge = 200;
enum class animaux {Vide = 0 ,Renard = 1 , Lapin = 2 };
enum class Genre {femelle = 0, homme = 1};
struct Animal {
    Animal() :  c{Coord(0,0)}{
        NbDeVie = -1;
        Id = -1;
        Age = 0;
        type = animaux::Vide;
        int a = rand()%2;
        genre = Genre(a);
    }
    Animal(animaux, Coord , int ) ;
    animaux getType() const { return type;};
    int GetNbDeVie() const {return NbDeVie;}
    Coord GetCoord() const {return  c;}
    Genre GetGenre() const {return genre;}
    int getId() const {return Id;}
    void SetCoord(Coord);
    void ReduitVie();
    void MangeLap();
    bool Reproduit(int) const;
    bool EraseRenard() const;
    bool Vieillit() const;
    void Veillit();
    friend  std::ostream& operator<<(std::ostream& ,  Animal );
private:
    Coord c;
    int Id;
    int NbDeVie;
    int Age;
    animaux type;
    Genre genre;
};
#endif //PROJETRENARDLAPIN_ANIMAL_HPP
