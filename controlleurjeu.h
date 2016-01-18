#ifndef CONTROLLEURJEU_H
#define CONTROLLEURJEU_H

#include "partie.h"
#include "affichagejeu.h"

class ControlleurJeu
{
public:
    ControlleurJeu(Partie* part);

private:
    Partie* m_Partie;
    AffichageJeu* m_Affichage;

    void InitControlleur(Partie* part);
};

#endif // CONTROLLEURJEU_H
