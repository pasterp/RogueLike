#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

//TODO : A définir
#include "entite.h"

class Creature : public Entite
{

protected:
    char* m_Nom;
    Couleur* m_CouleurNom;
    float m_VieActuelle;
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
    void recevoirDegats(float degat, int typeDegats);
    float attaquer(Creature* cible);
    void addBonusAttribut(int attributIndex, float multiplicateur);
    void setAttribut(int attributIndex, float valeur);
    float getAttribut(int attributIndex);
    inline bool isVivant() { return ((int)m_VieActuelle > 0); }
    inline float getVieActuelle(){ return m_VieActuelle; }
    void deplacer(int x, int y);

    static const int INDEX_MAX            = 6;

    static const int INDEX_VIE            = 0; //VIE = VIE_MAX !!
    static const int INDEX_FORCE          = 1; // degat physique
    static const int INDEX_DEXTERITE      = 2; // esquive
    static const int INDEX_CHANCE         = 3; // coup crititque
    static const int INDEX_AFFINITE       = 4; // cout en magie, niveau de sort
    static const int INDEX_INTELLIGENCE   = 5; // res magie, degat magie
    static const int INDEX_ENDURANCE      = 6; //ENDURANCE = déf / resistance physique

    static const int DEGATS_PHYSIQUES     = 0;
    static const int DEGATS_MAGIQUES      = 1;

private:
    void initCreature(int x, int y, char* nom, float valeurAttributs, float valeurModificateur);
};

#endif // CREATURE_H
