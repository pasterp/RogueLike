#include "case.h"

Case::Case()
{
    InitCase('#', true, true, false, &Couleurs::BLANC, &Couleurs::GRIS);
}

Case::Case(char s, bool d, bool v, bool p, Couleur *visible, Couleur *nonvisible)
{
    InitCase(s,d,v,p,visible, nonvisible);
}

void Case::InitCase(char s, bool d, bool v, bool p, Couleur *visible, Couleur *nonvisible){
    m_CouleurNonvisible = nonvisible;
    m_CouleurVisible = visible;
    m_Symbole = s;
    m_Decouverte = d;
    m_Visible = v;
    m_Passable = p;
}

