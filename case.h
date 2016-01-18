#ifndef CASE_H
#define CASE_H

#include <vector>

#include "couleur.h"
#include "objet.h"

class Case
{
public:
    Case();

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

#endif // CASE_H
