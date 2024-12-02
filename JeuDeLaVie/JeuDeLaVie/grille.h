#pragma once
#include <iostream>
#include <vector>
#include "etat_case.h"

struct Grille {
    int largeur;
    int hauteur;
    std::vector<EtatCase> grille;
};

Grille grille_def() {
    int l = 0, h = 0;

    while (true) {
        std::cout << "Donnez la hauteur de la grille : ";
        std::cin >> h;
        if (h > 0) {
            break;
        }
        else {
            std::cout << "La valeur doit etre un nombre positif !" << std::endl;
        }
    }

    while (true) {
        std::cout << "Donnez la largeur de la grille : ";
        std::cin >> l;
        if (l > 0) {
            break;
        }
        else {
            std::cout << "La valeur doit etre un nombre positif !" << std::endl;
        }
    }

    Grille resultat;
    resultat.largeur = l;
    resultat.hauteur = h;
    resultat.grille.resize(l * h, EtatCase::MORT);

    return resultat;
}
