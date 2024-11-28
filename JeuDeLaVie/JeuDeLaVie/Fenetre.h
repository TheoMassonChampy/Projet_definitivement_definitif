#pragma once
#include "jeu.h"
#include <SFML/Graphics.hpp>

class Fenetre {
private:
	sf::Font arial;
public:
	Jeu jeu;
	sf::RenderWindow window;

	Fenetre();

	void click(sf::Event::MouseButtonEvent mouseEvent);
	void afficherGrille();
	void afficherEtat();
};