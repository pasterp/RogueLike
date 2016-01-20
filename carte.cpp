#include "carte.h"

Carte::Carte()
{
    InitCarte(5, 5);
}

Carte::Carte(int x, int y)
{
    InitCarte(x, y);
}

void Carte::centrerSur(int x, int y)
{
    m_CentreX = x;
    m_CentreY = y;
}

std::vector<std::vector<Case> > Carte::getGrille(int x, int y)
{
    std::vector<std::vector<Case> > carteTronquee;
    carteTronquee = std::vector<std::vector<Case> >(y, std::vector<Case>(x, VIDE));
    int xMin, xMax, yMin, yMax;
    //Centrer l'image sur (centreX,centreY)
    xMin = (m_CentreX - x/2.0);
    xMax = (m_CentreX + x/2.0);
    yMax = (m_CentreY + y/2.0);
    yMin = (m_CentreY - y/2.0);
    for (int j=yMin; j < yMax; j++){
        for (int i=xMin; i < xMax; i++){
            if (j >= m_TailleY || j<0 || i<0 || i >= m_TailleX){
                //On laisse la casse générer vide
            }else{
                //Sinon on copie la case que l'on a déjà
                carteTronquee[j-yMin][i-xMin] = m_Grille[j][i];
            }
        }
    }
    return carteTronquee;
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
                m_Grille[j][i] = Case('.', true, true, true, &Couleurs::CYAN, &Couleurs::GRIS);
            }
        }
    }
}
