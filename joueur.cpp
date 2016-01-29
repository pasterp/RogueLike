#include "joueur.h"

Joueur::Joueur(int x, int y) : Creature(x,y)
{
    InitEntite(x,y,'@', &Couleurs::ORANGE);
    m_Faim = 5;
}

void Joueur::deplacer(int x, int y)
{
    Creature::deplacer(x, y);
    if(isVivant())
        m_Faim-=0.25;
    if (m_Faim <= 0){
        m_VieActuelle-=1;
        m_Faim = 4;
    }
}

char Joueur::getSymbole()
{
    return (isVivant()) ? Entite::getSymbole() : 'x';
}

