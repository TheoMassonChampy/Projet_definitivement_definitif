#include "fenetre.h"
#include "grille.h"
#include <iostream>

Fenetre::Fenetre() : window(sf::VideoMode(800, 600), "Jeu de la vie !") {

	if (!arial.loadFromFile("arial.ttf")) {
		std::cout << "ERREUR CHARGEMENT POLICE" << std::endl;
	}

	sf::Vector2u size = window.getSize();

	ligne_h_1 = sf::RectangleShape(sf::Vector2f(size.x, 5));
	ligne_h_1.setFillColor(sf::Color::Black);
	ligne_h_1.setPosition(0, size.y / lignes);

	ligne_h_2 = sf::RectangleShape(sf::Vector2f(size.x, 5));
	ligne_h_2.setFillColor(sf::Color::Black);
	ligne_h_2.setPosition(0, (size.y / lignes) * 2);


	ligne_v_1 = sf::RectangleShape(sf::Vector2f(size.x, 5));
	ligne_v_1.setFillColor(sf::Color::Black);
	ligne_v_1.setPosition(size.x / colonnes, 0);
	ligne_v_1.setRotation(90);

	ligne_v_2 = sf::RectangleShape(sf::Vector2f(size.x, 5));
	ligne_v_2.setFillColor(sf::Color::Black);
	ligne_v_2.setPosition((size.x / colonnes) * 2, 0);
	ligne_v_2.setRotation(90);
}