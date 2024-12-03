#ifndef GRILLE_H
#define GRILLE_H
#include "etat_case.h"
#include <vector>
#include <iostream>

class Grille {
private:

public:
    int largeur, hauteur, taille_grille;

    std::vector<EtatCase> grilledejeu;

    std::vector<EtatCase> grille_def();
    std::vector<int> return_grille();
    std::vector<EtatCase> Chargement_grille_fichier();


    // D�claration de la m�thode grille_def
    std::vector<EtatCase> grille = grille_def();

    Grille();  // D�claration du constructeur

};

#endif  // GRILLE_H