#include "affichagejeu.h"

AffichageJeu::~AffichageJeu()
{
    glfwTerminate();
}

AffichageJeu::AffichageJeu(Partie* p)
{
    initAffichageJeu(p, 20, 16, "Debug!");
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
    std::vector<std::vector<Case> > grille = carte->getGrille(m_TailleX, m_TailleY, 5, 5);
    std::cout << "X: " << carte->getTailleX() << " Y: " << carte->getTailleY() << std::endl;
    std::cout << "X demandé: " << m_TailleX << " Y demandé : " << m_TailleY << std::endl;

    for(int i=0; i < carte->getTailleY(); i++){
        for(int j=0; j < carte->getTailleX(); j++){
            std::cout << grille[i][j].getSymbole();
        }
        std::cout << std::endl;
    }

}

void AffichageJeu::afficherMessage(std::string s){
    std::cout << s << std::endl;
}

bool AffichageJeu::renduIteration()
{
    //TODO : Rendu OpenGL ici
    glfwSwapBuffers(m_Window);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

    m_Font->Render("Je suis un premier test", -1, FTPoint(m_X, m_Y));
    m_X++;
    m_Y = (m_X%2 == 0) ? m_Y : m_Y+1;

    glfwPollEvents();
    return glfwWindowShouldClose(m_Window);
}


void AffichageJeu::initAffichageJeu(Partie* p, int x, int y, std::string s){
    std::cout << "Initialisation affichage..." << std::endl;
    m_Partie = p;
    m_TailleX = x;
    m_TailleY = y;
    m_Titre = s.c_str();
    if(!glfwInit()){
        std::cout << "GLFW non initialisé !" << std::endl;
        return;
    }
    m_Window = glfwCreateWindow(20*m_TailleX, 20*m_TailleY, m_Titre, NULL, NULL);

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

    glViewport(0, 0, 20*m_TailleX, 20*m_TailleY);

    m_Font = new FTGLPixmapFont("/home/pascal/Documents/Projets/QtCreator/Roguelike/FantasqueSansMono-Regular.ttf");
    m_Font->FaceSize(20, 20);
    m_X = 0;
    m_Y = 0;
}
