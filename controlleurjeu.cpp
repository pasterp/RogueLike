#include "controlleurjeu.h"

ControlleurJeu::ControlleurJeu(Partie* part)
{
    InitControlleur(part);
}

void ControlleurJeu::InitControlleur(Partie *part){
    m_Partie = part;
    m_Affichage = new AffichageJeu(part, m_Partie->getCarte()->getTailleX(),m_Partie->getCarte()->getTailleY());
    m_Affichage->registerListener(this);
    m_Affichage->afficherMessage("Initialisation controlleur...");

    while(!m_Affichage->renduIteration()){
    }
}

void ControlleurJeu::keyPressed(int key){
    switch ( key ){
        case GLFW_KEY_DOWN:
            m_Partie->deplacer(0, -1);
            break;
        case GLFW_KEY_UP:
            m_Partie->deplacer(0, +1);
            break;
        case GLFW_KEY_LEFT:
            m_Partie->deplacer(-1, 0);
            break;
        case GLFW_KEY_RIGHT:
            m_Partie->deplacer(+1, 0);
            break;
    }
}
