#ifndef CONTROLLEURJEU_H
#define CONTROLLEURJEU_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "partie.h"
#include "affichagejeu.h"
#include "keylistener.h"

class ControlleurJeu : public keyListener
{
public:
    ControlleurJeu(Partie* part);
    void keyPressed(int key);

private:
    Partie* m_Partie;
    AffichageJeu* m_Affichage;

    void InitControlleur(Partie* part);
};

#endif // CONTROLLEURJEU_H
