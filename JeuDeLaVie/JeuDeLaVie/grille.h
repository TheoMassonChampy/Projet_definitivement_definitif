#ifndef GRILLE_H
#define GRILLE_H
#include "etat_case.h"
#include <vector>
#include <iostream>
#include <string>

class Grille {
private:

public:
    int largeur, hauteur, taille_grille;

    std::vector<EtatCase> grilledejeu;

    std::vector<EtatCase> grille_def();
    std::vector<int> grille_vers_nombre();
    void affiche_grille(std::vector<int> res);
    std::vector<EtatCase> nombre_vers_grille(std::string valeurs);
    std::vector<EtatCase> Chargement_grille_fichier();
    bool Sauvegarde_fichier();

    // D�claration de la m�thode grille_def
    std::vector<EtatCase> grille = grille_def();

    Grille();  // D�claration du constructeur

};

#endif  // GRILLE_H