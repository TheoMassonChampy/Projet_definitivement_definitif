#pragma once
#include <iostream>

class Grille {
private:
    int temp, h, l;
    cout << "\nHauteur de la grille ? : ";
public:
    int lignes, colonnes;
    std::cout << "Combien de lignes souhaites-tu : ";
    std::cin >> lignes;

    std::cout << "Combien de colonnes souhaites-tu : ";
    std::cin >> colonnes;

    short grille[lignes * colonnes];
    for (int i = 0; i < lignes * colonnes; i++)
        grille[i] = 0;
};