#ifndef CONTROLLEURJEU_H
#define CONTROLLEURJEU_H

#include "partie.h"
#include "affichagejeu.h"
#include "keylistener.h"

//TODO: Intégrer la gestion des inputs utilisateurs
//TODO: Register a fonction depuis l'affichage

class ControlleurJeu : public keyListener
{
public:
    ControlleurJeu(Partie* part);
    void keyPressed();

private:
    Partie* m_Partie;
    AffichageJeu* m_Affichage;

    void InitControlleur(Partie* part);
};

#endif // CONTROLLEURJEU_H
