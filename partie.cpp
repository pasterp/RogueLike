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

std::vector<Entite> Partie::getEntites()
{
    return m_Entites;
}

void Partie::InitPartie(int x, int y)
{
    m_Entites = std::vector<Entite>(0);
    m_Carte = new Carte(x, y);
    m_Joueur = new Joueur(x/2, y/2);
    m_Entites.push_back(*m_Joueur);
}
