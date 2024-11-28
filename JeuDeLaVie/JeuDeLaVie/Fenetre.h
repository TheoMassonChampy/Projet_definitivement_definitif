#pragma once
#include "jeu.h"
#include <SFML/Graphics.hpp>

class Fenetre {
private:
	sf::RectangleShape ligne_v_1;
	sf::RectangleShape ligne_v_2;
	sf::RectangleShape ligne_h_1;
	sf::RectangleShape ligne_h_2;
	sf::Font arial;
public:
	Jeu jeu;
	sf::RenderWindow window;

	Fenetre();

	void click(sf::Event::MouseButtonEvent mouseEvent);
	void afficherGrille();
};