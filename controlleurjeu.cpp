#include "controlleurjeu.h"

ControlleurJeu::ControlleurJeu(Partie* part)
{
    InitControlleur(part);
}

void ControlleurJeu::InitControlleur(Partie *part){
    m_Partie = part;
    m_Affichage = new AffichageJeu(part);
    m_Affichage->afficherMessage("Initialisation controlleur...");

    int i = 0;
    char tour[20];
    while(!m_Affichage->renduIteration()){
        sprintf(tour, "Frame n°%i.", i);
        m_Affichage->afficherMessage(tour);
        i++;
    }
}

void ControlleurJeu::keyPressed(){

}
