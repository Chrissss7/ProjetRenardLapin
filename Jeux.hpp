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
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

struct Jeu{
    
    //constructors
    
    Jeu();
    
    /**
     * @brief ajoute un animal a des coordonnes donnees
     * 
     * @param a l'animal en question
     * @param c les coordonnees auqyels il doit etre ajoute
     */
    void ajouteAnimal(animaux a, Coord c);
    
    /**
     * @brief deplace aleatoirement un animal donnees.
     * le processus peut changer entre de type d'animaux different
     * 
     * @param c les coordonnes de l'animal en question
     */
    void Deplace(Coord c);
    
    /**
     * @brief genere toute les case vide voisine a une case donnee
     * 
     * @param ind les coordonnes de la case 
     * @return Ensemble contenant toute les coordonnes des case vide voisine de "ind"
     */
    Ensemble CaseV(Coord ind);
    
    /**
     * @brief genere un ensemble de toutes les case voisine a une case donnees tel que ces dernieres contiennent tous des lapins
     * 
     * @param ind les coordonnes de la case 
     * @return Ensemble contenant toute les coordonnes des case contenant des lapins et voisine a "ind"
     */
    Ensemble CaseLap(Coord ind);
    
    /**
     * @brief genere un ensemble de toutes les case voisine a une case donnees tel que ces dernieres contiennent tous des renards
     * 
     * @param ind les coordonnes de la case 
     * @return Ensemble contenant toute les coordonnes des case contenant des renards et voisine a "ind"
     */
    Ensemble CaseRen(Coord ind);
    
    /**
     * @brief regroupe tous les animaux de la population en des groupe de meme type
     *  
     * @return pair<vector<int>,vector<int>> tel que first contient tous les renard et second tous les lapins 
     */
    pair<vector<int>,vector<int>> GetIdRenLap();
    
    /**
     * @brief dessine la grille dans un fichier de format ppm qui a un temps/nombre de tours donnees
     *  
     * @param compteurFichier un entier qui represente le n-ieme etat de la simulation.
     */
    void dessineGrille(int compteurFichier);
    
    /**
     * @brief dessine la grille dans une fenetre et update la fenetre afin quel affiche le nouveau contenue
     *  
     * @param la fenetre dans laquel ont projette la simulation
     */
    void renderGrille(sf::RenderWindow &window);
    
    /**
     * @brief deplace un animal d'un point a un autre
     * 
     * @param initial coordonnees de depart / de l'animal dans le present
     * @param arriver coordonnees d'arriver
     * @param id l'id de l'animal
     */
    void Deplace(Coord initial,Coord arriver,int id);
    
    /**
     * @brief supprime un animal du jeu, vide la case qu'il occupait et son id
     * 
     * @param id id de l'animal a enlever
     * @param a les coordonnes de ce dernier
     */
    void supprime(int id , Coord a);
    
    /**
     * @brief verifie si la case choisi contient une des voisin de la meme espece mais d'un genre different
     * 
     * @param ind les coordonne de la case
     * @return true ont y trouve un voisin de la meme espece mais d'un genre different
     * @return false sinon
     */
    bool TypeOpposeProche(Coord ind); 
    
    bool Test();
private:
    
    // attributs
    
    Population pop{};
    Grille grille{};

};
#endif //PROJETRENARDLAPIN_JEUX_HPP
