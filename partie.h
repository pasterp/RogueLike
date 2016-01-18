#ifndef PARTIE_H
#define PARTIE_H

#include <vector>

#include "entite.h"
#include "inventaire.h"
#include "carte.h"
#include "joueur.h"

class Partie
{
public:
    Partie();
    Partie(int x, int y);

    Carte* getCarte();
private:
    Carte* m_Carte;
    Joueur* m_Joueur;
    std::vector<Entite> m_Entites();

    void InitPartie(int x, int y);
};

#endif // PARTIE_H