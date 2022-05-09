#include "Jeux.hpp"
#include "SFML/Graphics.hpp"
int main() {
    Jeu a{};
    int compteur;
    for (compteur = 0; compteur < 700; compteur++) {
        vector<int>ren = a.GetIdRenLap().first;
        vector<int>lap = a.GetIdRenLap().second;
        while(not lap.empty()){
            int val = rand()%lap.size();
            a.Deplace(lap[val]);
            lap.erase(lap.begin()+val);
        }
        while(not ren.empty()){
            int val = rand()%ren.size();
            a.Deplace(ren[val]);
            ren.erase(ren.begin()+val);
        }
        a.dessineGrille(compteur);
    }
    return 0;
}
