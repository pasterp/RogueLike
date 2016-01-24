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
    std::vector<Entite*> getEntites();
    bool deplacer(int xoffset, int yoffset);
    int getViePerso();
    int getXPerso() { return m_Joueur->getX(); }
    int getYPerso() { return m_Joueur->getY(); }
    bool isEntiteHere(int x, int y);
private:
    Carte* m_Carte;
    Joueur* m_Joueur;
    std::vector<Entite*> m_Entites;

    void InitPartie(int x, int y);
};

#endif // PARTIE_H
