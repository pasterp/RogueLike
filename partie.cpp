#include "partie.h"

Partie::Partie()
{
    InitPartie(20, 20);
}

Partie::Partie(int x, int y)
{
    InitPartie(x, y);
}

Carte *Partie::getCarte()
{
    return m_Carte;
}

void Partie::InitPartie(int x, int y)
{
    m_Carte = new Carte(x, y);
    m_Joueur = new Joueur(x/2, y/2);
}
