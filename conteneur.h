#ifndef CONTENEUR_H
#define CONTENEUR_H

//TODO : Créer cette classe

#include "objet.h"
#include "inventaire.h"

class Conteneur : public Objet, Inventaire
{
public:
    Conteneur();
};

#endif // CONTENEUR_H
