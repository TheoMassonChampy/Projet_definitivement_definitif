#include "grille.h"
#include "etat_case.h"

// Définition du constructeur
Grille::Grille() : largeur(0), hauteur(0), taille_grille(0) {

}

std::vector<EtatCase> Grille::grille_def() {
    while (true) {
        std::cout << "Donnez la hauteur de la grille : ";
        std::cin >> hauteur;
        if (hauteur != 0) {
            break;
        }
        else {
            std::cout << "La valeur doit etre un nombre positif !" << std::endl;
        }
    }
    while (true) {
        std::cout << "Donnez la largeur de la grille : ";
        std::cin >> largeur;
        if (largeur != 0) {
            break;
        }
        else {
            std::cout << "La valeur doit être un nombre positif !" << std::endl;
        }
    }
    // Initialisation de la grille avec des cases MORT
    std::vector<EtatCase> grille;
    grille.resize(largeur * hauteur, EtatCase::MORT);
    taille_grille = largeur * hauteur;
    for (int i = 0; i < taille_grille; i++) {
        std::cout << "" ,grille[i];
        std::cout << i << std::endl;
    }

    return grille;
}

std::vector<int> Grille::return_grille() {
    std::vector<int> res;
    res.resize(Grille::taille_grille, 0);
        for (int i = 0; i < Grille::taille_grille; i++) {
            if (Grille::grille[i] == EtatCase::MORT)
            {
                res[i] = 0;
            }

            else if (Grille::grille[i] == EtatCase::VIVANT)
            {
                res[i] = 1;
            }
        } //TODO à revoir
        return res;
}