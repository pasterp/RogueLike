#include "carte.h"

Carte::Carte()
{
    InitCarte(5, 5);
}

Carte::Carte(int x, int y)
{
    InitCarte(x, y);
}

void Carte::vision()
{
    for (int j = 0; j < m_TailleY; j++){
        for (int i = 0; i < m_TailleX; i++){
            //parcourt des cases et si assez proche du joueur, illuminate sinon go dark
            if( sqrt(pow(i-m_CentreX, 2) + pow(j-m_CentreY, 2)) < 5){
                m_Grille[j][i].setVisible(true);
                m_Grille[j][i].setDecouverte(true);
            }else{
                m_Grille[j][i].setVisible(false);
            }
        }
    }
}

void Carte::centrerSur(int x, int y)
{
    m_CentreX = x;
    m_CentreY = y;
}

std::vector<std::vector<Case> > Carte::getGrille(int x, int y, int* offsetX, int* offsetY)
{
    std::vector<std::vector<Case> > carteTronquee;
    carteTronquee = std::vector<std::vector<Case> >(y, std::vector<Case>(x, VIDE));
    int xMin, xMax, yMin, yMax;
    //Centrer l'image sur (centreX,centreY)
    *offsetX = xMin = (m_CentreX - x/2.0);
    xMax = (m_CentreX + x/2.0);
    yMax = (m_CentreY + y/2.0);
    *offsetY = yMin = (m_CentreY - y/2.0);
    for (int j=yMin; j < yMax; j++){
        for (int i=xMin; i < xMax; i++){
            if (j >= m_TailleY || j<0 || i<0 || i >= m_TailleX){
                //On laisse la case générer vide
            }else{
                //Sinon on copie la case que l'on a déjà
                carteTronquee[j-yMin][i-xMin] = m_Grille[j][i];
            }
        }
    }
    return carteTronquee;
}

std::vector<Case> Carte::operator[](int a)
{
    return m_Grille[a];
}

void Carte::InitCarte(int x, int y){
    m_TailleX = x;
    m_TailleY = y;

    m_CentreX = m_TailleX/2;
    m_CentreY = m_TailleY/2;

    m_Grille = std::vector<std::vector<Case> >(m_TailleY);
    for (int j=0; j < m_TailleY; j++){
        m_Grille[j] = std::vector<Case>(m_TailleX, Case());
        for (int i=0; i < m_TailleX; i++){
            if (j==0 || i==0 || j == m_TailleY-1 || i == m_TailleX-1){
                m_Grille[j][i] = MUR;
            }else{
                m_Grille[j][i] = Case('.', false, false, true, &Couleurs::CYAN, &Couleurs::GRIS);
            }
        }
    }
}
