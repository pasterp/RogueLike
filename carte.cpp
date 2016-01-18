#include "carte.h"

Carte::Carte()
{
    InitCarte(5, 5);
}

Carte::Carte(int x, int y)
{
    InitCarte(x, y);
}

void Carte::InitCarte(int x, int y){
    m_TailleX = x;
    m_TailleY = y;

    m_Grille = std::vector<std::vector<Case> >(m_TailleY, std::vector<Case>(m_TailleX, Case()));
}
