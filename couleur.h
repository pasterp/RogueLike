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

namespace Couleurs {
    static Couleur BLANC        =   Couleur(252,252,252);
    static Couleur GRIS         =   Couleur(189,195,199);
    static Couleur GRIS_FONCE   =   Couleur(75,71,67);
    static Couleur NOIR         =   Couleur(49,54,59);
    static Couleur VERT         =   Couleur(39,174,96);
    static Couleur BLEU         =   Couleur(61,174,233);
    static Couleur CYAN         =   Couleur(147,206,233);
    static Couleur ROUGE        =   Couleur(218,68,83);
    static Couleur ORANGE       =   Couleur(246,116,0);
}

#endif // COULEUR_H
