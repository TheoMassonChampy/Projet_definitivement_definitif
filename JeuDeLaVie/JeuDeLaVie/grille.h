#pragma once
#include <iostream>


class Grille {
public:
    int setup_size(int coordonates) {
        int size;
        bool error_marker = false;
        while (!error_marker) {
            if (coordonates == 0) {
                std::cout << "Donnez la hauteur de la grille : ";
            }
            else if (coordonates == 1) {
                std::cout << "Donnez la largeur de la grille : ";
            }
            std::cin >> size;
            if (size > 0) {
                return size;
                error_marker = true;
            }
            else {
                std::cout << "La valeur doit être un nombre positif !";
            }
        }
    }

    int nombre_de_cases = setup_size(0) * setup_size(1); //définition de la hauteur et largeur de la grille 
    short grille[nombre_de_cases]; //définition d'une grille à une dimension basée sur les dimensions données par le user


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