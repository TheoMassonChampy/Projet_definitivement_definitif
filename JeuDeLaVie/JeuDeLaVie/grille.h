#ifndef GRILLE_H
#define GRILLE_H
#include "etat_case.h"
#include <vector>
#include <iostream>

class Grille {
private:
    std::vector<EtatCase> grille_def();

public:
    int largeur, hauteur, taille_grille;
    std::vector<EtatCase> grilledejeu;

    // D�claration de la m�thode grille_def
    std::vector<EtatCase> grille;

    Grille();  // D�claration du constructeur

};

#endif  // GRILLE_H