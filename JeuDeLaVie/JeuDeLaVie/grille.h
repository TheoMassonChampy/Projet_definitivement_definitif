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

    // Déclaration de la méthode grille_def
    std::vector<EtatCase> grille;

    Grille();  // Déclaration du constructeur

};

#endif  // GRILLE_H