#ifndef PROJETRENARDLAPIN_JEUX_HPP
#define PROJETRENARDLAPIN_JEUX_HPP
#include "Animal.hpp"
#include "Population.hpp"
#include "Grille.hpp"
#include "Coord.hpp"
#include "Ensemble.hpp"
#include <algorithm>
#include <iostream> // pour cout
#include <iomanip> // pour setfill, setw
#include <sstream> // pour ostringstream
#include <fstream> // pour ofstream
#include <string>
struct Jeu{
    Jeu();
    void ajouteAnimal(animaux , Coord);
    void Deplace(Coord);
    Ensemble CaseV(Coord);
    Ensemble CaseLap(Coord);
    Ensemble CaseRen(Coord);
    pair<vector<int>,vector<int>> GetIdRenLap();
    void dessineGrille(int);
    bool Test();
    void Deplace(Coord,Coord,int);
    void supprime(int , Coord);
    bool TypeOpposeProche(Coord);
private:
    Population pop{};
    Grille grille{};

};
#endif //PROJETRENARDLAPIN_JEUX_HPP
