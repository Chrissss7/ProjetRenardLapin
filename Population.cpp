#include "Population.hpp"
Population::Population() {
    CaseV = {};
    for (int i = 0; i < TAILLE*TAILLE; i++) {
        CaseV.push_back(i);
        pop[i] = {animaux::Vide, Coord(i), -1};
    }
}

void Population::ReduitVie(int id) {
    pop[id].ReduitVie();
}
void Population::Veillit(int id) {
    pop[id].Veillit();
}
vector<int> Population::getIdsRen() const {
    vector<int>id;
    for(int i = 0 ; i < TAILLE * TAILLE; i ++){
        if(pop[i].getId() != -1 and pop[i].getType() == animaux::Renard)
            id.push_back(pop[i].GetCoord().toInt());
    }
    return id;
}
vector<int> Population::getIdsLap() const {
    vector<int>id;
    for(int i = 0 ; i < TAILLE * TAILLE; i ++){
        if(pop[i].getId() != -1 and pop[i].getType() == animaux::Lapin)
            id.push_back(pop[i].GetCoord().toInt());
    }
    return id;
}
void Population::IncrVie(int id) {
    pop[id].MangeLap();
}
void Population::SetCoord(Coord ind, int id) {
    pop[id].SetCoord(ind);
}
int Population::reserve() {
    if(CaseV.empty())
        throw invalid_argument("PAS BON");
    int a = rand()%CaseV.size();
    int val = CaseV[a];
    CaseV.erase(CaseV.begin()+a);
    return val;
}
int Population::addAnimal(animaux type , Coord c) {
    int id = reserve();
    Animal ajoute(type,c,id);
    pop[id] = ajoute;
    return id;
}
void Population::delAnimal(int a) {
    Animal enlev = pop[a];
    pop[a] = {animaux::Vide,enlev.GetCoord(),-1};
    CaseV.push_back(a);
}
Animal Population::getAnimal(int id) const {
    if(id > TAILLE * TAILLE or id == -1)
        throw invalid_argument("Indiced invalide");
    return pop[id];
}

int Population::NombreTotalAnimaux() const {
    return TAILLE*TAILLE - CaseV.size();
}
