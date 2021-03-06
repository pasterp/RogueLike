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
    inline float Rf(){return m_Rouge/255.0;}
    inline float Vf(){return m_Vert/255.0;}
    inline float Bf(){return m_Bleu/255.0;}

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
    static Couleur JAUNE        =   Couleur(246, 220, 18);
}

#endif // COULEUR_H
