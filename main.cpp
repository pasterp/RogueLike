#include <iostream>


#include "partie.h"
#include "controlleurjeu.h"

using namespace std;

int main()
{
    cout << "Roguelike Reborn ! v0.01" << endl;

    Partie partie = Partie(20,16);
    cout << "Initialisation modèle..." << endl;
    ControlleurJeu controlleur(&partie);


    return 0;
}

