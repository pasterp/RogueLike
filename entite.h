#ifndef ENTITE_H
#define ENTITE_H

//TODO : A préciser

#include "couleur.h"

class Entite
{
public:
    Entite();
    Entite(int x, int y);

    virtual inline char getSymbole(){ return m_Symbole; }
    inline Couleur* getCouleur(){ return m_Couleur; }
    inline int getX(){ return m_X; }
    inline int getY(){ return m_Y; }
    inline void setX(int x){ m_X = x; }
    inline void setY(int y){ m_Y = y; }
    inline bool isPassable(){ return m_Passable; }
protected:
    char m_Symbole;
    Couleur* m_Couleur;
    int m_X;
    int m_Y;
    bool m_Passable;

    void InitEntite(int x, int y, char c, Couleur* coul);
};

#endif // ENTITE_H
