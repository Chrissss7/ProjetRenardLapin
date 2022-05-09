#include "Ensemble.hpp"
Ensemble::Ensemble() {
    card=0;
}

std::ostream& operator<<(std::ostream& out , Ensemble a){
    for(int i = 0 ; i <a.card ; i ++)
        out << a.tab[i] << " ";
    return out;
}

bool Ensemble::estVide() const{
    return card == 0;
}
int Ensemble::cardinal() const {
    return card;
}
void Ensemble::ajoute(int a) {
    if(card == MAXcard)
        throw std::invalid_argument("Trop grand calme toi");
    else
        tab[card] = a;
    card ++;
}
int Ensemble::Tire(){
    if(card == 0)
        throw std::invalid_argument("Ne peut pas retirer un element d'un ensemble vide");
    int a = rand()%card;
    int val = tab[a];
    std::remove(tab.begin(),tab.end(),val);
    card--;
    return val;
}
