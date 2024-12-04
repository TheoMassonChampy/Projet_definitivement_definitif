#include "fenetre.h"
#include <iostream>

// Constructeur
Fenetre::Fenetre() : window(sf::VideoMode(1200, 900), "Jeu de la vie !") {
{
    sf::RectangleShape rectangle(sf::Vector2f(20, 900));
    rectangle.setPosition(350, 0);
    rectangle.setFillColor(sf::Color::Black);

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(rectangle);

        window.display();
    }

    return 0;
}

    sf::Vector2u size = window.getSize();
}

// Méthode pour afficher la grille
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

// Méthode pour gérer les clics de souris
void Fenetre::click(sf::Event::MouseButtonEvent mouseEvent) {
    if (mouseEvent.button == sf::Mouse::Left) {
        sf::Vector2u size = window.getSize();
        int x = mouseEvent.x / (size.x / 3);
        int y = mouseEvent.y / (size.y / 3);
        std::cout << x << "," << y << std::endl;
    }
}

