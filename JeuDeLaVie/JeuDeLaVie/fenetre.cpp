#include "fenetre.h"
#include <iostream>

// Constructeur
Fenetre::Fenetre() : window(sf::VideoMode(1200, 900), "Jeu de la vie !") {
{
        sf::RectangleShape rectangle_separation(sf::Vector2f(850, 900));
        rectangle_separation.setPosition(350, 0);
        rectangle_separation.setFillColor(sf::Color::Black);

        sf::RectangleShape rectangle_play(sf::Vector2f(100, 100));
        rectangle_play.setPosition(250, 800);
        rectangle_play.setFillColor(sf::Color(255, 87, 51));

        sf::Font font;
        if (!font.loadFromFile("arial.ttf")) {
            return -1;
        }

        sf::Text title;
        title.setFont(font);
        title.setString("JEU DE LA VIE");
        title.setCharacterSize(35);
        title.setFillColor(sf::Color::Black);
        title.setStyle(sf::Text::Bold);

        title.setPosition(35, 30);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);

            window.draw(rectangle_separation);
            window.draw(rectangle_play);

            window.draw(title);
            window.display();
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

