#include "Jeux.hpp"

/**
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
*/

int main() {
    srand(time(0));
    Jeu a{};
    sf::RenderWindow window(sf::VideoMode(TAILLE*3,  TAILLE*3), "test", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    window.setFramerateLimit(30);
    sf::Event ev;
    while (window.isOpen())
    {
 

        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed :
                window.close();
                break;
            
            case sf::Event::MouseButtonPressed :
                if (ev.mouseButton.button == sf::Mouse::Left){
                    window.close();
                    break;
                }
            
            default:
                break;
            }
        }
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
        a.renderGrille(window);


    }
    return 0;
}
