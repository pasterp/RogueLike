#ifndef OBJET_H
#define OBJET_H

//TODO : Définir les caractéristiques

#include <string>

class Objet
{
public:
    Objet();
private:
    std::string m_NomObjet;
    int niveau;
    float poids;

    void InitObjet(std::string nom, int niv, float p);
};

#endif // OBJET_H
