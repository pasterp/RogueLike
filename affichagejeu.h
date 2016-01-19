#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H

#include <iostream>

#include "partie.h"
//TODO : Intégrer OpenGL
//TODO : Intégrer la gestion de la police

class AffichageJeu
{
public:
    AffichageJeu(Partie* p);
    AffichageJeu(Partie* p, int x, int y);
    AffichageJeu(Partie* p, int x, int y, std::string s);

    void afficherJeu();
    void afficherMessage(std::string s);
private:
    Partie* m_Partie;
    int m_TailleX;
    int m_TailleY;
    const char* m_Titre;


    void initAffichageJeu(Partie* p, int x, int y, std::string s);
};

#endif // AFFICHAGEJEU_H
