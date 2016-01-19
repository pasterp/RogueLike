#ifndef CASE_H
#define CASE_H

#include <vector>

#include "couleur.h"
#include "objet.h"

//TODO : Ajouter une couleur de fond ? (ou si passable colorer quand visible et noir sinon ?)
//TODO : Gestion de l'inventaire d'une case (intégrer inventaire ?)

class Case
{
public:
    Case();
    Case(char s, bool d, bool v, bool p, Couleur* visible, Couleur* nonvisible);

    inline char getSymbole(){ return m_Symbole; }
private:
    char m_Symbole;
    bool m_Decouverte;
    bool m_Visible;
    bool m_Passable;
    Couleur* m_CouleurVisible;
    Couleur* m_CouleurNonvisible;
    std::vector<Objet> m_Objets;

    void InitCase(char s, bool d, bool v, bool p, Couleur* visible, Couleur* nonvisible);
};

static Case VIDE = Case('.', false, false, false, &Couleurs::GRIS_FONCE, &Couleurs::GRIS_FONCE);
static Case MUR = Case('#', true, true, false, &Couleurs::BLANC, &Couleurs::GRIS);

#endif // CASE_H
