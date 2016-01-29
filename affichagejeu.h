#ifndef AFFICHAGEJEU_H
#define AFFICHAGEJEU_H

#include <iostream>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <FTGL/ftgl.h>

#include "partie.h"
#include "carte.h"
#include "case.h"
#include "keylistener.h"

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
    void registerListener(keyListener* keyl);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
    Partie* m_Partie;
    int m_TailleX;
    int m_TailleY;
    float m_CharLargeur;
    float m_CharHauteur;
    const char* m_Titre;
    GLFWwindow* m_Window;
    FTGLPixmapFont* m_Font;
    static std::vector<keyListener*> m_Listeners;

    double lastTime;
    int nbFrame;

    void initAffichageJeu(Partie* p, int x, int y, std::string s);
};



#endif // AFFICHAGEJEU_H
