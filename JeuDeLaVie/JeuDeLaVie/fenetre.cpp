#include "fenetre.h"
#include <iostream>

// Constructeur
Fenetre::Fenetre() : window(sf::VideoMode(800, 600), "Jeu de la vie !") {
    // Chargement de la police
    if (!font.loadFromFile("Halo Dek.ttf")) {
        std::cout << "�RREUR CHARGEMENT POLICE" << std::endl;
    }
    // On peut r�cup�rer la taille de la fen�tre ici si n�cessaire
    sf::Vector2u size = window.getSize();
}

// M�thode pour afficher la grille
void Fenetre::afficherGrille() {
    sf::Vector2u size = window.getSize();
    sf::RectangleShape rectangle(sf::Vector2f(50.0f, 150.0f));

    for (int x = 0; x < jeu.grilledejeu.taille_grille; x++) {
        if (jeu.grilledejeu.grilledejeu[x] == EtatCase::VIVANT) {
            rectangle.setFillColor(sf::Color::White);
        }
        else if (jeu.grilledejeu.grilledejeu[x] == EtatCase::MORT) {
            rectangle.setFillColor(sf::Color::Black);
        }

        window.draw(rectangle);
    }
}

// M�thode pour g�rer les clics de souris
void Fenetre::click(sf::Event::MouseButtonEvent mouseEvent) {
    if (mouseEvent.button == sf::Mouse::Left) {
        sf::Vector2u size = window.getSize();
        int x = mouseEvent.x / (size.x / 3);
        int y = mouseEvent.y / (size.y / 3);
        std::cout << x << "," << y << std::endl;
    }
}
