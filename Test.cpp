using namespace std;

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Jeux.hpp"

TEST_CASE("Animal class"){
    for(int i = 0 ; i < TAILLE * TAILLE ; i++){
        Animal test(animaux(i%3),Coord(i) , i);
        CHECK(test.GetCoord() == Coord(i/TAILLE,i%TAILLE));
        CHECK(test.getId() == Coord(i).toInt());
        CHECK(test.getType() == animaux(i%3));
        if(i%3 == 1)
            CHECK(test.GetNbDeVie() == foodinit);
        else
            CHECK(test.GetNbDeVie() == -1);
    }
    Animal test(animaux::Renard, Coord(1,5) , 9);
    test.MangeLap();
    CHECK(test.GetNbDeVie() == min(foodinit + foodlapin,Maxfood));
    test.ReduitVie();
    CHECK(test.GetNbDeVie() == min(foodinit+foodlapin,Maxfood)-1);
    CHECK_FALSE(test.EraseRenard());
    for(int i = 0 ; i < min(foodinit+foodlapin,Maxfood) -1 ; i++)
        test.ReduitVie();
    CHECK(test.EraseRenard());
}
TEST_CASE("Coord Class" ){
    Coord c(0,0);
    Ensemble a;
}
TEST_CASE("Population Class"){
    Population pop{};
    int id = pop.addAnimal(animaux::Renard,Coord(5,0));
    CHECK(pop.getAnimal(id).getType()== animaux::Renard);
    CHECK(pop.getAnimal(id).getId() == id);
    CHECK(pop.getAnimal(id).GetCoord() == Coord(5,0));
    pop.delAnimal(id);
    CHECK(pop.getAnimal(id).getType()== animaux::Vide);
    CHECK(pop.getAnimal(id).getId() == -1);
    CHECK(pop.getAnimal(id).GetCoord() == Coord(5,0));
    Population test{};
    for(int i = 0  ; i < TAILLE * TAILLE ; i++){
        int a = test.reserve();
    }
    CHECK_THROWS_AS(test.reserve(),invalid_argument);
}
TEST_CASE("Grille class"){
    Grille grille{};
    for(int i = 0 ; i < TAILLE* TAILLE ; i++) {
                CHECK(grille.CaseVide(Coord(i)));
                grille.setCase(Coord(i) , i);
                CHECK(grille.GetId(Coord(i)) == i);
                grille.videCase(Coord(i));
                CHECK(grille.CaseVide(Coord(i)));
    }
}

TEST_CASE("Jeux class") {
    Jeu a{};
    CHECK(a.Test());
}
int main(int argc, const char **argv) {
    doctest::Context context(argc, argv);
    int test_result = context.run();
    if (context.shouldExit()) return test_result;
    return 0;
}
