#ifndef CARTE_H
#define CARTE_H

#include <vector>
#include <iostream>
#include <math.h>

#include "case.h"

class Carte
{
public:
    Carte();
    Carte(int x, int y);

    void vision();
    void centrerSur(int x, int y);
    inline std::vector<std::vector<Case*> > getGrille() {return m_Grille;}
    std::vector<std::vector<Case*> > getGrille(int x, int y, int* offsetX, int* offsetY);
    inline int getTailleX(){return m_TailleX;}
    inline int getTailleY(){return m_TailleY;}

    std::vector<Case*> operator[](int a);
private:
    int m_TailleX, m_CentreX;
    int m_TailleY, m_CentreY;
    std::vector<std::vector<Case*> > m_Grille;

    void InitCarte(int x, int y);
};

#endif // CARTE_H
