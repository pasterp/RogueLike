#include "couleur.h"

Couleur::Couleur(int r, int v, int b)
{
    InitCouleur(r,v,b,255);
}

void Couleur::InitCouleur(int r, int v, int b, int a){
    m_Alpha = a;
    m_Rouge = r;
    m_Vert  = v;
    m_Bleu  = b;
}
