#ifndef ENTITE_H
#define ENTITE_H

//TODO : A préciser

#include "couleur.h"

class Entite
{
public:
    Entite();
    Entite(int x, int y);
protected:
    char m_Symbole;
    Couleur* m_Couleur;
    int m_X;
    int m_Y;
};

#endif // ENTITE_H
