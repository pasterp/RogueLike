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
    m_Carte->centrerSur(m_Joueur->getX(), m_Joueur->getY());
    m_Carte->vision();
    return m_Carte;
}

std::vector<Entite*> Partie::getEntites()
{
    return m_Entites;
}

bool Partie::isEntiteHere(int x, int y){
    bool yes = false;
    for(int i = 0; i < m_Entites.size() && !yes; i++)
            yes = m_Entites[i]->getX() == x && m_Entites[i]->getY() == y && !m_Entites[i]->isPassable();
    return yes;
}

bool Partie::deplacer(int xoffset, int yoffset)
{
    bool deplacementPossible = false;
    int x = m_Joueur->getX();
    int y = m_Joueur->getY();

    deplacementPossible = (*m_Carte)[y+yoffset][x+xoffset].isPassable() && !isEntiteHere(x+xoffset,y+yoffset);

    if (deplacementPossible){
       m_Joueur->setX(x+xoffset);
       m_Joueur->setY(y+yoffset);
    }

    return deplacementPossible;
}

int Partie::getViePerso()
{
    return (int)m_Joueur->getAttribut(Joueur::INDEX_VIE);
}

void Partie::InitPartie(int x, int y)
{
    m_Entites = std::vector<Entite*>(0);
    m_Carte = new Carte(x, y);
    m_Joueur = new Joueur(x/2, y/2);
    m_Entites.push_back(m_Joueur);
    m_Entites.push_back(new Creature(5,5));
}
