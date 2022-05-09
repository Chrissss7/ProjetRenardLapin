#ifndef PROJETRENARDLAPIN_ENSEMBLE_HPP
#define PROJETRENARDLAPIN_ENSEMBLE_HPP
#include <array>
#include <iostream>
#include <algorithm>
const int MAXcard = 8;
struct Ensemble{
    friend std::ostream& operator<<(std::ostream&, Ensemble);
    
    //constuctors
    
    Ensemble();
    
    //methodes
    
    /**
     * @brief verifie si l'ensemble est vide
     * 
     * @return true si il est vide
     * @return false sinon
     */
    bool estVide()const;
    
    /**
     * @brief 
     * 
     * @return le cardinal de l'ensemble
     */
    int cardinal() const;
    
    /**
     * @brief aujoute un element a l'ensemble si ce dernier n'est pas deja plein (cardinalmax = 8)
     * 
     * @param a l'element a rajoute
     */
    void ajoute(int);
    
    /**
     * @brief tirage aleatoire d'un element de l'ensemble si ce dernier n'est pas vide, l'element tire sera retire de l'ensemble
     * 
     * @return l'element choisi
     */
    int Tire();
private :
    
    //attributs 
    
    std::array<int,MAXcard> tab;
    int card;
};
#endif //PROJETRENARDLAPIN_ENSEMBLE_HPP
