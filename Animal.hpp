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
    
    //constructors
    
    Animal() :  c{Coord(0,0)}{
        NbDeVie = -1;
        Id = -1;
        Age = 0;
        type = animaux::Vide;
        int a = rand()%2;
        genre = Genre(a);
    }
    Animal(animaux, Coord , int ) ;
    
    //methodes
    
    /** @brief Get the Type of the animal
     * 
     * @return animaux (vide | Renard | Lapin) 
     */
    animaux getType() const { return type;};
    
    /**
     * @brief 
     * 
     * @return le nombre de point de vie l'animal
     */
    int GetNbDeVie() const {return NbDeVie;}
    
    /**
     * @brief 
     * 
     * @return l'emplacement / les coordonnes de l'animal
     */
    Coord GetCoord() const {return  c;}
    
    /**
     * @brief voit si l'animal est un mal ou une femelle
     * 
     * @return le Genre de l'animal
     */
    Genre GetGenre() const {return genre;}
    
    /**
     * @brief 
     * 
     * @return l'id de l'animal
     */
    int getId() const {return Id;}
    
    /**
     * @brief Set the Coordinate of the animal
     * 
     * @param a the coordinates
     */
    void SetCoord(Coord);
    
    /**
     * @brief reduit le nombre de point de vie d'un animal
     * 
     */
    void ReduitVie();
    
    /**
     * @brief augmente les point de vie d'un animal (Renard en principe ) de 'foodlapin' apres que ce dernier est mager un lapin
     * 
     */
    void MangeLap();
    
    /**
     * @brief voit si l'animal est capable de ce reproduire
     * 
     * @param VoisinV nombre de case vide a proximite de l'animal 
     * @return true si il peut se reproduire (c'est a dire si le nombre de vie >= foodReprod si l'animal est un renard ou si VoisinV >= MinFreeBirthLapin si l'animal est un lapin)
     * @return false sinon
     */
    bool Reproduit(int) const;
    
    /**
     * @brief voit si animal est mort ou pas
     * 
     * @return true si ce dernier est mort
     * @return false sinon
     */
    bool EraseRenard() const;
    
    /**
     * @brief voit si un animal a atteint son age maximal 
     * 
     * @return true si son age depasse l'age maximal
     * @return false sinon
     */
    bool Vieillit() const;
    
    /**
     * @brief incremente l'age de l'animal
     * 
     */
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
