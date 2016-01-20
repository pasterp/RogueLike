#include "entite.h"

Entite::Entite()
{
    InitEntite(0,0,'X', &Couleurs::ROUGE);
}

Entite::Entite(int x, int y)
{
    InitEntite(x,y,'X', &Couleurs::ROUGE);
}

void Entite::InitEntite(int x, int y, char c, Couleur *coul)
{
    m_X = x;
    m_Y = y;

    m_Symbole = c;

    m_Couleur = coul;
}

