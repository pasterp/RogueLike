#ifndef COULEUR_H
#define COULEUR_H


class Couleur
{
public:
    int m_Rouge;
    int m_Vert;
    int m_Bleu;
    int m_Alpha;
public:
    Couleur(int r, int v, int b);

private:
    void InitCouleur(int r, int v, int b, int a);
};


//TODO : Trouver de jolies couleurs
namespace Couleurs {
    static Couleur BLANC = Couleur(0,0,0);
    static Couleur GRIS  = Couleur(120,120,120);
    static Couleur NOIR  = Couleur(255,255,255);
    static Couleur VERT  = Couleur(0,255,0);
    static Couleur BLEU  = Couleur(0,0,255);
    static Couleur ROUGE = Couleur(255,0,0);
}

#endif // COULEUR_H
