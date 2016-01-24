#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

//TODO : A définir
#include "entite.h"

class Creature : public Entite
{

private:
    char* m_Nom;
    Couleur* m_CouleurNom;
    float* m_Attr_Vie;
    float* m_Attr_Force;
    float* m_Attr_Dexterite;
    float* m_Attr_Chance;
    float* m_Attr_Affinite;
    float* m_Attr_Intelligence;
    float* m_Attr_Endurance;
    float* m_AttrTotal; // Tableau de float contenant les attributs
    float* m_ModifieursAttr; // Tableau des modificateurs
    //float m_PoidsMax; -- Lier à l'inventaire ?
    bool sexeMasculin;
public:
    Creature(int x, int y);
    void recevoirDegats(float degat);
    float attaquer(Creature* cible);
    void addBonusAttribut(int attributIndex, float multiplicateur);
    void setAttribut(int attributIndex, float valeur);
    float getAttribut(int attributIndex);

    static const int INDEX_MAX            = 6;
    static const int INDEX_VIE            = 0;
    static const int INDEX_FORCE          = 1;
    static const int INDEX_DEXTERITE      = 2;
    static const int INDEX_CHANCE         = 3;
    static const int INDEX_AFFINITE       = 4;
    static const int INDEX_INTELLIGENCE   = 5;
    static const int INDEX_ENDURANCE      = 6;

private:
    void initCreature(int x, int y, char* nom, float valeurAttributs, float valeurModificateur);
};

#endif // CREATURE_H
