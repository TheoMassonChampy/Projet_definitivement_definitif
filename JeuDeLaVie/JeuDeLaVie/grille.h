#pragma once
#include <iostream>
#include <vector>
#include "etat_case.h"


class Grille {
public:
    int largeur, hauteur, taille_grille;
    bool error_marker = false;

    std::vector<EtatCase> grille_def() {
        while (!error_marker) {
            std::cout << "Donnez la hauteur de la grille : ";
            std::cin >> hauteur;
            if (hauteur != 0) {
                break;
            }
            else {
                std::cout << "La valeur doit etre un nombre positif !";
            }
        }
        while (!error_marker) {
            std::cout << "Donnez la largeur de la grille : ";
            std::cin >> largeur;
            if (largeur != 0) {
                break;
            }
            else {
                std::cout << "La valeur doit etre un nombre positif !";
            }
        }
        std::vector<EtatCase> grille;
        grille.resize(largeur * hauteur, EtatCase::MORT);

        taille_grille = largeur * hauteur;


        return grille;
    }
    

    std::vector<EtatCase> grille = grille_def();

    //int lignes, colonnes;
    //std::cout << "Combien de lignes souhaites-tu : ";
    //std::cin >> lignes;

    //std::cout << "Combien de colonnes souhaites-tu : ";
    //std::cin >> colonnes;

    //short grille[lignes * colonnes];
    //for (int i = 0; i < lignes * colonnes; i++)
        //grille[i] = 0;

    Grille() = default;
};