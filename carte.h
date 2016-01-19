#ifndef CARTE_H
#define CARTE_H

#include <vector>

#include "case.h"

//TODO : Gérer la carte selon une taille voulue et centrée sur un point

class Carte
{
public:
    Carte();
    Carte(int x, int y);

    void centrerSur(int x, int y);
    inline std::vector<std::vector<Case> > getGrille() {return m_Grille;}
    inline int getTailleX(){return m_TailleX;}
    inline int getTailleY(){return m_TailleY;}
private:
    int m_TailleX;
    int m_TailleY;
    std::vector<std::vector<Case> > m_Grille;

    void InitCarte(int x, int y);
};

#endif // CARTE_H
