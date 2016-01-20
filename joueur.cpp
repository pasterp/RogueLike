#include "joueur.h"

Joueur::Joueur(int x, int y) : Creature(x,y)
{
    InitEntite(x,y,'@', &Couleurs::ORANGE);
}

