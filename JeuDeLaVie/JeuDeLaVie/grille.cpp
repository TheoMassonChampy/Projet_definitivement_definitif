#include "grille.h"
#include "etat_case.h"
#include <fstream>
#include <string>
#include <iostream>

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

std::vector<int> Grille::grille_vers_nombre() {
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

    return res;
}

void Grille::affiche_grille(std::vector<int> res) {
    int counter = 0;
    for (int i = 1; i < hauteur + 1; i++) {
        for (int j = 1; j < largeur + 1; j++) {
            std::cout << res[counter] << " ";
            counter += 1;
        }
        std::cout << std::endl;
    }
}

std::vector<EtatCase> Grille::nombre_vers_grille(const std::string& input) {
    // Définition d'un vecteur d'EtatCase
    std::vector<EtatCase> etats;

    // Parcourir chaque caractère du string
    for (char c : input) {
        if (c == '0') {
            etats.push_back(EtatCase::MORT);   // Ajouter MORT si c'est '0'
        }
        else if (c == '1') {
            etats.push_back(EtatCase::VIVANT); // Ajouter VIVANT si c'est '1'
        }
        else {
            // Gestion des caractères non valides (facultatif)
            std::cerr << "Caractère invalide rencontré : " << c << '\n';
        }
    }

    return etats;
}
    
    /*std::vector<EtatCase> res;
    res.resize(valeurs.length(), 0);
    for (int i = 0; i < valeurs.size(); i++) {
        if (strcmp(valeurs[i],"0") == 0)
        {
            res[i] = EtatCase::MORT;
        }

        else if (valeurs[i] == "1")
        {
            res[i] = EtatCase::VIVANT;
        }
    }
    return res;*/


std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

std::vector<EtatCase> Grille::Chargement_grille_fichier() {
    std::vector<EtatCase> resultat;
    std::cout << "Faites entrer quand vous aurez complété le fichier 'file.txt' avec votre setup ..." << std::endl;
    std::cin;
    std::ifstream fichier("file.txt");
    if (fichier) {
        std::string lignes;
        while (std::getline(fichier, lignes)) {
            std::cout << lignes << std::endl;
        }
        std::vector<std::string> parse_result = split(lignes, "|");
        //for (auto i : parse_result) std::cout << i << std::endl;
        largeur = std::stoi(parse_result[1]);
        hauteur = std::stoi(parse_result[2]);
        grille.resize(hauteur * largeur);
        grille = nombre_vers_grille(parse_result[0]);
    }
    else { std::cout << "Impossible de lire le fichier ..." << std::endl; }
    
    return resultat;
}

bool Grille::Sauvegarde_fichier() {
    std::string const f("file_out.txt");
    std::ofstream flux(f.c_str());

    flux.open(f);

    if (!flux.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier ..." << std::endl;
        return 1;
    }
    
    //std::getline(grille_vers_nombre(), f);

    flux << f << std::endl;

    // Fermer le fichier
    flux.close();

    std::cout << "Texte écrit dans le fichier 'output.txt'." << std::endl;
    return true;
}