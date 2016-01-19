#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <FTGL/ftgl.h>

#include "partie.h"

//TODO : Intégrer OpenGL
//TODO : Intégrer la gestion de la police

class AffichageJeu
{
public:
    /**
     * Destructeur (ferme OpenGl)
     **/
    ~AffichageJeu();
    /**
     * Creer un affichage pour une partie
     **/
    AffichageJeu(Partie* p /** Pointeur vers une instance de Partie */);

    /**
     * Creer un affichage pour une partie
     **/
    AffichageJeu(Partie* p /** Pointeur vers une instance de Partie */, int x /** Largeur de la fenetre */, int y /** Hauteur de la fenetre */);
    AffichageJeu(Partie* p /** Pointeur vers une instance de Partie */, int x /** Largeur de la fenetre */, int y /** Hauteur de la fenetre */, std::string s /** Titre de la fenêtre */);

    void afficherJeu();
    void afficherMessage(std::string s);
    bool renduIteration();
private:
    Partie* m_Partie;
    int m_TailleX, m_X;
    int m_TailleY, m_Y;
    const char* m_Titre;
    GLFWwindow* m_Window;
    FTGLPixmapFont* m_Font;

    void initAffichageJeu(Partie* p, int x, int y, std::string s);
};

#endif // AFFICHAGEJEU_H
