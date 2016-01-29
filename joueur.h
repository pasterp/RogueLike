#ifndef JOUEUR_H
#define JOUEUR_H

#include "entite.h"
#include "creature.h"

//TODO : A definir

class Joueur : public Creature
{
public:
    Joueur(int x, int y);
    void deplacer(int x, int y);
    int getFaim() { return (int)m_Faim; }
    char getSymbole();
private:
    float m_Faim;
};

#endif // JOUEUR_H
