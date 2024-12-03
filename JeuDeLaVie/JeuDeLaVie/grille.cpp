#include "grille.h"
#include "etat_case.h"
#include <fstream>

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
    }
    int counter = 0;
    for (int i = 1; i < hauteur + 1; i++) {
        for (int j = 1; j < largeur + 1; j++) {
            std::cout << res[counter] << " ";
            counter += 1;
        }
        std::cout << std::endl;
    }

    return res;
}

//std::vector<EtatCase> Grille::Chargement_grille_fichier() {}

bool Grille::Sauvegarde_fichier() {
    return true;
}