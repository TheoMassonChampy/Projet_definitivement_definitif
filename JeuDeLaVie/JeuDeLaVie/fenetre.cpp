#include "fenetre.h"
#include "grille.h"
#include "etat_case.h"
#include <iostream>

int lignes = 3;
int colonnes = 3;

Fenetre::Fenetre() : window(sf::VideoMode(800, 600), "Jeu de la vie !") {

	if (!arial.loadFromFile("arial.ttf")) {
		std::cout << "ERREUR CHARGEMENT POLICE" << std::endl;
	}

	sf::Vector2u size = window.getSize();
}

void Fenetre::afficherGrille()
{
	sf::Vector2u size = window.getSize();

	for (int x = 0; x < jeu.grille.size(); x++)
	{
		sf::Text text;
		if (jeu.grille.grille[x] == EtatCase::VIVANT) {
			sf::RectangleShape rectangle(sf::Vector2f(grille.largeur, 150)); // Dimensions du rectangle (largeur, hauteur)
			rectangle.setFillColor(sf::Color::White);
		}
		else if (jeu.grille.grille[x] == EtatCase::MORT) {
			
		}

		window.draw(rectangle);
	}
}

void Fenetre::click(sf::Event::MouseButtonEvent mouseEvent)
{
	if (mouseEvent.button == sf::Mouse::Left)
	{
		sf::Vector2u size = window.getSize();
		int x = mouseEvent.x / (size.x / 3);
		int y = mouseEvent.y / (size.y / 3);
		std::cout << x << "," << y << std::endl;
	}
}