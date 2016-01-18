#include "affichagejeu.h"

AffichageJeu::AffichageJeu(Partie* p)
{
    initAffichageJeu(p, 50, 50, "Debug!");
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
    std::vector<std::vector<Case> > grille = carte->getGrille();

    std::cout << "X: " << carte->getTailleX() << " Y: " << carte->getTailleY() << std::endl;

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


void AffichageJeu::initAffichageJeu(Partie* p, int x, int y, std::string s){
    std::cout << "Initialisation affichage..." << std::endl;
    m_Partie = p;
    m_TailleX = x;
    m_TailleY = y;
    m_Titre = s.c_str();
}
