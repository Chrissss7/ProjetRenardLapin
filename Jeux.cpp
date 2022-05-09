#include "Jeux.hpp"
Jeu::Jeu() {
    for(int i = 0 ; i < TAILLE * TAILLE; i ++){
        int random = rand()%99;
        if(random < 7){
            ajouteAnimal(animaux::Renard,Coord(i));
        }else if(random < 27)
            ajouteAnimal(animaux::Lapin,Coord(i));
    }
}


void Jeu::ajouteAnimal(animaux a, Coord c) {
    int id = pop.addAnimal(a, c);
    grille.setCase(c, id);
}
/*ostream& operator<<(ostream& out,Jeu a){
    for(int i = 0 ; i < TAILLE  ;i ++){
        for(int j = 0 ; j < TAILLE; j++){
            int ID = a.grille.GetId(Coord(i,j));
            cout << a.pop.getAnimal(ID) << " " ;
        }
        cout << endl;
    }
    return out;
}*/
Ensemble Jeu::CaseLap(Coord ind) {
    Ensemble acot = ind.voisines();
    Ensemble acotV = Ensemble();
    while(!acot.estVide()) {
        Coord a = acot.Tire();
        if (not grille.CaseVide(a)) {
            if (pop.getAnimal(grille.GetId(a)).getType() == animaux::Lapin) {
                acotV.ajoute(a.toInt());
            }
        }
    }
    return acotV;
}

Ensemble Jeu::CaseV(Coord ind) {
    Ensemble acot = ind.voisines();
    Ensemble acotV = Ensemble();
    while(! acot.estVide()){
        Coord a = acot.Tire();
        if(grille.CaseVide(a)){
            acotV.ajoute(a.toInt());
        }
    }
    return acotV;
}
Ensemble Jeu::CaseRen(Coord ind){
    Ensemble acot = ind.voisines();
    Ensemble acotV = Ensemble();
    while(!acot.estVide()) {
        Coord a = acot.Tire();
        if (not grille.CaseVide(a)) {
            if (pop.getAnimal(grille.GetId(a)).getType() == animaux::Renard) {
                acotV.ajoute(a.toInt());
            }
        }
    }
    return acotV;
}
bool Jeu::TypeOpposeProche(Coord ind) {
    Animal a = pop.getAnimal(grille.GetId(ind));
    if (a.getType() == animaux::Lapin) {
        Ensemble acotL = CaseLap(ind);
        while (not acotL.estVide()) {
            Coord coord = acotL.Tire();
            Animal an = pop.getAnimal(grille.GetId(coord));
            if (int(an.GetGenre()) != int(a.GetGenre())){
                return true;
            }
        }
        return false;
    }else if(a.getType() == animaux::Renard){
        Ensemble acotR = CaseRen(ind);
        while (not acotR.estVide()) {
            Coord Coord = acotR.Tire();
            Animal an = pop.getAnimal(grille.GetId(Coord));
            if (int(an.GetGenre()) != int(a.GetGenre())){
                return true;
            }
        }
        return false;
    }
    return false;
}

void Jeu::supprime(int id , Coord a) {
    pop.delAnimal(id);
    grille.videCase(a);
}
void Jeu::Deplace(Coord initial, Coord arriver , int id) {
    pop.SetCoord(arriver,id);
    grille.setCase(arriver, id);
    grille.videCase(initial);
}
void Jeu::Deplace(Coord c) {
    if (not grille.CaseVide(c)) {
        int ID =grille.GetId(c);
        Animal Adep = pop.getAnimal(ID);
        bool Reproduit = TypeOpposeProche(c);
        if (Adep.getType() == animaux::Renard) {
            Ensemble coordonner = CaseLap(c);
            bool Mange = true;
            if (coordonner.estVide()) {
                Mange = false;
                coordonner = CaseV(c);
            }
            if (Adep.EraseRenard() or Adep.Vieillit()) {
                supprime(ID,c);
            } else if (coordonner.cardinal() != 0) {
                pop.ReduitVie(ID);
                pop.Veillit(ID);
                Coord dep = coordonner.Tire();
                if (Mange) {
                    supprime(grille.GetId(dep) , dep);
                    pop.IncrVie(ID);
                }
                Deplace(c,dep,ID);
                if (Reproduit) {
                    float proba = rand()%99;
                    if(proba < ProbBirthRenard * 100 )
                        ajouteAnimal(animaux::Renard, c);
                }
            }
        } else if (Adep.getType() == animaux::Lapin) {
            Ensemble coordonner = CaseV(c);
            if(Adep.Vieillit()){
                supprime(ID,c);
            }else if (coordonner.cardinal() != 0) {
                pop.Veillit(ID);
                Coord deplacement = coordonner.Tire();
                Deplace(c,deplacement,ID);
                if (Adep.Reproduit(coordonner.cardinal()+1) and Reproduit){
                    float proba = rand()%99;
                    if(proba < ProbBirthLapin*100)
                        ajouteAnimal(animaux::Lapin,c);
                }
            }
        }
    }
}
pair<vector<int> , vector<int> > Jeu::GetIdRenLap() {
    return make_pair(pop.getIdsRen(),pop.getIdsLap());
}
void Jeu::dessineGrille(int compteurFichier) {
    int i,j;
    int r,g,b;
    ostringstream filename;
// creation d’un nouveau nom de fichier de la forme img347.ppm
    filename << "img"  << compteurFichier << ".ppm";
    compteurFichier++;
    cout << "Ecriture dans le fichier : " << filename.str() << endl;
// ouverture du fichier
    ofstream fic(filename.str(), ios::out | ios::trunc);
// ecriture de l’entete
    fic << "P3" << endl
        << TAILLE << " " << TAILLE << " " << endl
        << 255 << " " << endl;
// ecriture des pixels
    for (i = 0; i < TAILLE; i++){
        for (j = 0; j < TAILLE; j++){
            int ID = grille.GetId(Coord(i,j));
            if(ID == -1){
                r = 255; g= 255; b = 255;
            }else if (pop.getAnimal(ID).getType() == animaux::Renard){
                r = 255; g = 0; b = 0;
            }else if(pop.getAnimal(ID).getType() == animaux::Lapin){
                r = 0; g = 255; b = 0;
            }else{
                r = 255;g=255;b=255;
            }
// ecriture de la couleur dans le fichier
            fic << r << " " << g << " " << b << " ";
        }
// fin de ligne dans l’image
        fic << endl;
    }
// fermeture du fichier
    fic.close();
}

bool Jeu::Test() {
    pair<vector<int>,vector<int>>IDS = GetIdRenLap();
    for(int i : IDS.first){
        if(pop.getAnimal(grille.GetId(i)).getType() != animaux::Renard){
            return false;
        }
    }
    for(int i : IDS.second){
        if(pop.getAnimal(grille.GetId(i)).getType() != animaux::Lapin){
            return false;
        }
    }
    for(int i = 5 ; i < 15 ; i ++){
        Ensemble ren = CaseRen(Coord(i));
        Ensemble lap = CaseLap(Coord(i));
        Ensemble vide = CaseV(Coord(i));
        while(! ren.estVide()){
            Coord c = ren.Tire();
            if(pop.getAnimal(grille.GetId(c)).getType() !=  animaux::Renard)
                return false;
        }
        while(! lap.estVide()){
            Coord c = lap.Tire();
            if(pop.getAnimal(grille.GetId(c)).getType() !=  animaux::Lapin)
                return false;
        }
        while(! vide.estVide()){
            Coord c = vide.Tire();
            if(grille.GetId(c) !=  -1)
                return false;
        }
    }
    return true;
}

