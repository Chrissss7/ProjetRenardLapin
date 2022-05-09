#ifndef PROJETRENARDLAPIN_POPULATION_HPP
#define PROJETRENARDLAPIN_POPULATION_HPP
#include "Animal.hpp"
#include <algorithm>
#include <array>
#include <vector>

struct Population {
    Population();
    int reserve();/*Reserve un nouvel identifiant pour un animal*/
    Animal getAnimal(int ) const;/*Renvoie l'animal qui correspond a l'id donner*/
    int addAnimal(animaux,Coord);
    void delAnimal(int);
    void ReduitVie(int );
    void IncrVie(int );
    void Veillit(int );
    void SetCoord(Coord , int);
    vector<int> getIdsRen() const;
    vector<int> getIdsLap() const;
private:
    std::array<Animal,TAILLE*TAILLE> pop;
    std::vector<int>CaseV;
};

#endif //PROJETRENARDLAPIN_POPULATION_HPP
