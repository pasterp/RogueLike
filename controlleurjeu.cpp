#include "controlleurjeu.h"

ControlleurJeu::ControlleurJeu(Partie* part)
{
    InitControlleur(part);
}

void ControlleurJeu::InitControlleur(Partie *part){
    m_Partie = part;
    m_Affichage = new AffichageJeu(part);
    m_Affichage->afficherMessage("Initialisation controlleur...");

    m_Affichage->afficherJeu();
}
