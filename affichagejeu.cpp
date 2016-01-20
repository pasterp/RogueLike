#include "affichagejeu.h"

AffichageJeu::~AffichageJeu()
{
    glfwTerminate();
}

AffichageJeu::AffichageJeu(Partie* p)
{
    initAffichageJeu(p, 50, 25, "Debug!");
}

AffichageJeu::AffichageJeu(Partie* p, int x, int y)
{
    initAffichageJeu(p, x, y, "Debug2!");
}

AffichageJeu::AffichageJeu(Partie* p, int x, int y, std::string s){
    initAffichageJeu(p, x, y, s);
}

void AffichageJeu::afficherJeu()
{
    Carte* carte = m_Partie->getCarte();
    std::vector<Entite> entites = m_Partie->getEntites();
    carte->centrerSur(25,12);
    std::vector<std::vector<Case> > grille = carte->getGrille(m_TailleX, m_TailleY);

    std::string c = "!";
    Case* cc;
    Couleur* coul;
    bool entTrouve;
    for(int i=0; i < carte->getTailleY(); i++){
        for(int j=0; j < carte->getTailleX(); j++){
            entTrouve = false;
            for (unsigned int e = 0; e < entites.size() && !entTrouve; e++){
                if (i==entites[e].getY() && j==entites[e].getX() && grille[i][j].isVisible()){
                    entTrouve = true;

                    c[0] = entites[e].getSymbole();
                    coul = entites[e].getCouleur();

                    glPushAttrib(GL_ALL_ATTRIB_BITS);
                    glDisable(GL_LIGHTING);
                    glDisable(GL_DEPTH_TEST);

                    glPixelTransferf(GL_RED_BIAS, coul->Rf()-1.0f);
                    glPixelTransferf(GL_GREEN_BIAS, coul->Vf()-1.0f);
                    glPixelTransferf(GL_BLUE_BIAS, coul->Bf()-1.0f);


                    m_Font->Render(c.c_str(), -1, FTPoint(m_CharLargeur * j, m_CharHauteur * i));

                    glPopAttrib();
                }
            }
            if(!entTrouve){
                cc = &grille[i][j];
                c[0] = cc->getSymbole();
                coul = cc->getCouleur();

                glPushAttrib(GL_ALL_ATTRIB_BITS);
                glDisable(GL_LIGHTING);
                glDisable(GL_DEPTH_TEST);

                glPixelTransferf(GL_RED_BIAS, coul->Rf()-1.0f);
                glPixelTransferf(GL_GREEN_BIAS, coul->Vf()-1.0f);
                glPixelTransferf(GL_BLUE_BIAS, coul->Bf()-1.0f);


                m_Font->Render(c.c_str(), -1, FTPoint(m_CharLargeur * j, m_CharHauteur * i));

                glPopAttrib();
            }
        }
    }
}

void AffichageJeu::afficherMessage(std::string s){
    std::cout << s << std::endl;
}

bool AffichageJeu::renduIteration()
{
    glfwSwapBuffers(m_Window);
    glClear(GL_COLOR_BUFFER_BIT);

    this->afficherJeu();

    glfwPollEvents();
    return glfwWindowShouldClose(m_Window);
}

void AffichageJeu::key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


void AffichageJeu::initAffichageJeu(Partie* p, int x, int y, std::string s){
    std::cout << "Initialisation affichage..." << std::endl;
    m_Partie = p;
    m_TailleX = x;
    m_TailleY = y;
    m_Titre = s.c_str();

    m_Font = new FTGLPixmapFont("/home/pascal/Documents/Projets/QtCreator/Roguelike/FantasqueSansMono-Regular.ttf");
    m_Font->FaceSize(12);

    m_CharLargeur = m_Font->Advance("A");
    m_CharHauteur = m_Font->LineHeight();

    if(!glfwInit()){
        std::cout << "GLFW non initialisé !" << std::endl;
        return;
    }
    m_Window = glfwCreateWindow(m_CharLargeur*(m_TailleX), m_CharHauteur*(m_TailleY), m_Titre, NULL, NULL);

    if (!m_Window)
    {
        std::cout << "Fenetre non initialisée !" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(m_Window);

    if(glewInit() != GLEW_OK){
        std::cout << "GLEW non initialisé !" << std::endl;
        return;
    }


    std::cout << "\tOpenGl Version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "\tGLWF Version: " << glfwGetVersionString() << std::endl;
    std::cout << "\tGLEW Version: " << glewGetString(GLEW_VERSION) << std::endl;

    glViewport(0, 0, m_CharLargeur*(m_TailleX), m_CharHauteur*(m_TailleY));
    glfwSetKeyCallback(m_Window, AffichageJeu::key_callback);

    glClearColor(Couleurs::GRIS_FONCE.Rf(), Couleurs::GRIS_FONCE.Vf(), Couleurs::GRIS_FONCE.Bf(), 1.0f);
}
