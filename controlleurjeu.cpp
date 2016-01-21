#include "controlleurjeu.h"

ControlleurJeu::ControlleurJeu(Partie* part)
{
    InitControlleur(part);
}

void ControlleurJeu::InitControlleur(Partie *part){
    m_Partie = part;
    m_Affichage = new AffichageJeu(part);
    m_Affichage->registerListener(this);
    m_Affichage->afficherMessage("Initialisation controlleur...");

    int i = 0;
    char tour[20];
    while(!m_Affichage->renduIteration()){
        sprintf(tour, "Frame n°%i.", i);
        m_Affichage->afficherMessage(tour);
        i++;
    }
}

void ControlleurJeu::keyPressed(int key){
    switch ( key ){
        case GLFW_KEY_DOWN:
            m_Affichage->afficherMessage("BAS");
            m_Partie->deplacer(0, -1);
            break;
        case GLFW_KEY_UP:
            m_Affichage->afficherMessage("HAUT");
            m_Partie->deplacer(0, +1);
            break;
        case GLFW_KEY_LEFT:
            m_Affichage->afficherMessage("GAUCHE");
            m_Partie->deplacer(-1, 0);
            break;
        case GLFW_KEY_RIGHT:
            m_Affichage->afficherMessage("DROITE");
            m_Partie->deplacer(+1, 0);
            break;
    }
}
