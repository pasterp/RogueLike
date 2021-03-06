#ifndef CASE_H
#define CASE_H

#include <vector>

#include "couleur.h"
#include "objet.h"

//TODO : Gestion de l'inventaire d'une case (intégrer inventaire ?)

class Case
{
public:
    Case();
    Case(char s, bool d, bool v, bool p, Couleur* visible, Couleur* nonvisible);

    inline char getSymbole(){ return m_Symbole; }
    inline char* getSymbole_(){ return &m_Symbole; }
    inline Couleur* getCouleur(){ return (m_Visible) ? m_CouleurVisible : m_CouleurNonvisible; }
    inline bool isVisible(){ return m_Visible; }
    inline bool isDecouverte(){ return m_Decouverte; }
    inline bool isPassable(){ return m_Passable; }
    inline void setVisible(bool b){ m_Visible = b; }
    inline void setDecouverte(bool b){ m_Decouverte = b; }
    void addObjet(Objet* obj){ m_Objets.push_back(obj);}
private:
    char m_Symbole;
    bool m_Decouverte;
    bool m_Visible;
    bool m_Passable;
    Couleur* m_CouleurVisible;
    Couleur* m_CouleurNonvisible;
    std::vector<Objet*> m_Objets;

    void InitCase(char s, bool d, bool v, bool p, Couleur* visible, Couleur* nonvisible);
};

static Case VIDE = Case(' ', false, false, false, &Couleurs::GRIS_FONCE, &Couleurs::GRIS_FONCE);
static Case MUR = Case('#', false, false, false, &Couleurs::BLANC, &Couleurs::GRIS);

#endif // CASE_H
