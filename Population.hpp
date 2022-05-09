#ifndef PROJETRENARDLAPIN_POPULATION_HPP
#define PROJETRENARDLAPIN_POPULATION_HPP
#include "Animal.hpp"
#include <algorithm>
#include <array>
#include <vector>

struct Population {
    
    //constructors
    
    Population();
    
    /**
     * @brief Reserve un nouvel identifiant pour un animal
     * 
     * @return int 
     */
    int reserve();
    
    /**
     * @brief Get the Animal object
     * 
     * @param id nu entier pointant vers un animal precis
     * @return Animal qui correspond a l'id donner
     */
    Animal getAnimal(int id) const;
    
    /**
     * @brief rajoute un animal a la population
     * 
     * @param type le type de l'animal (Lapin | Renard | vide)
     * @param c les coordonne de l'animal
     * @return int l'id de l'animal
     */
    int addAnimal(animaux type ,Coord c);
    
    /**
     * @brief enleve un animal de la population
     * 
     * @param a l'id de l'animal en question
     */
    void delAnimal(int a);
    
    /**
     * @brief Reduit la duree de vie d'un animal
     * 
     * @param id un entier qui pointe vers l'animal en question
     */
    void ReduitVie(int id);
    
    /**
     * @brief incremente la vie d'un animal si ce dernier est capable de manger un lapin
     * 
     * @param id l'id de l'animal en question
     */
    void IncrVie(int id);
    
    /**
     * @brief fait veillir un animal
     * 
     * @param id un entier qui pointe vers l'animal en question
     */
    void Veillit(int id);
    
    /**
     * @brief met en place les coordonnes d'un animal
     * 
     * @param ind les coordonnes a mettre en place
     * @param id l'id de l'animal en question
     */
    void SetCoord(Coord ind, int id);
    
    /** 
     * @brief Get the Ids Renard
     * 
     * @return vector<int> qui contient toutes les ids de tous les renards
     */
    vector<int> getIdsRen() const;
    
    /**
     * @brief Get the Ids Lapin
     * 
     * @return vector<int> qui contient toutes les ids de tous les lapins
     */
    vector<int> getIdsLap() const;
    
    /**
     * @brief compte le nombre d'animaux vivant dans la population
     * 
     * @return le nombre total d'animaux dans la population
     */
    int NombreTotalAnimaux() const;
private:
    
    // attributs
    
    std::array<Animal,TAILLE*TAILLE> pop;
    std::vector<int>CaseV;
};

#endif //PROJETRENARDLAPIN_POPULATION_HPP
