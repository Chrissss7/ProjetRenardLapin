#ifndef PROJETRENARDLAPIN_ENSEMBLE_HPP
#define PROJETRENARDLAPIN_ENSEMBLE_HPP
#include <array>
#include <iostream>
#include <algorithm>
const int MAXcard = 8;
struct Ensemble{
    friend std::ostream& operator<<(std::ostream&, Ensemble);
    Ensemble();
    bool estVide()const;
    int cardinal() const;
    void ajoute(int);
    int Tire();
private :
    std::array<int,MAXcard> tab;
    int card;
};
#endif //PROJETRENARDLAPIN_ENSEMBLE_HPP
