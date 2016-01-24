#include "creature.h"

Creature::Creature(int x, int y)
{
    initCreature(x, y, "Monstre", 5, 1.5);
}

float Creature::getAttribut(int attributIndex)
{
    return m_AttrTotal[attributIndex] * m_ModifieursAttr[attributIndex];
}

void Creature::initCreature(int x, int y, char *nom, float valeurAttributs, float valeurModificateur)
{
    m_Nom = nom;
    setX(x);
    setY(y);

    //On initialise les attributs
    m_AttrTotal = new float[INDEX_MAX+1];
    m_ModifieursAttr = new float[INDEX_MAX+1];
    for(int i = 0; i < INDEX_MAX+1; i++){
        m_AttrTotal[i] = valeurAttributs;
        m_ModifieursAttr[i] = valeurModificateur;
    }

    //on associe les pointeurs vers les bonnes cases:
    m_Attr_Vie = &m_AttrTotal[INDEX_VIE];
    m_Attr_Affinite = &m_AttrTotal[INDEX_AFFINITE];
    m_Attr_Chance = &m_AttrTotal[INDEX_CHANCE];
    m_Attr_Dexterite = &m_AttrTotal[INDEX_DEXTERITE];
    m_Attr_Endurance = &m_AttrTotal[INDEX_ENDURANCE];
    m_Attr_Force = &m_AttrTotal[INDEX_FORCE];
    m_Attr_Intelligence = &m_AttrTotal[INDEX_INTELLIGENCE];

}

