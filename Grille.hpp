#ifndef PROJETRENARDLAPIN_GRILLE_HPP
#define PROJETRENARDLAPIN_GRILLE_HPP
#include "Coord.hpp"
#include <iostream>
#include <array>
using Plateau = std::array<std::array<int,TAILLE>,TAILLE>;
struct Grille {
    
    //constructors 
    
    Grille();
    
    /**
     * @brief 
     * 
     * @param ind une coordonne donnees 
     * @return la valeur dans la grille au coordonne de ind
     */
    int GetId(Coord ind)const {return grille[ind.getX()][ind.getY()];}
    
    /**
     * @brief verifie si la case a l'indice choisi est vide
     * 
     * @param ind les coordonne de la case a verifier
     * @return true si la case est vide 
     * @return false sinon
     */
    bool CaseVide(Coord ind) const{return GetId(ind) == -1;}
    
    /**
     * @brief verifie si la case a l'indice choisi est vide
     * 
     * @param ind les coordonne de la case a verifier
     * @return true si la case est vide 
     * @return false sinon
     */
    void setCase(Coord ind , int val);
    
    /**
     * @brief vide une case donnees dans la grille
     * 
     * @param a les coordonnes de la case a vider
     */
    void videCase(Coord a);
    
private:
    
    //attributs
    
    Plateau grille{};
};
#endif //PROJETRENARDLAPIN_GRILLE_HPP
