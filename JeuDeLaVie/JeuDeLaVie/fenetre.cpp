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

void Fenetre::afficherGrille()
{
	window.draw(ligne_h_1);
	window.draw(ligne_h_2);
	window.draw(ligne_v_1);
	window.draw(ligne_v_2);

	sf::Vector2u size = window.getSize();

	for (int x = 0; x < 3; x++)
		for (int y = 0; y < 3; y++)
		{
			if (jeu.grille.grille[x][y] == EtatCase::VIVANT) {
				sf::Text text;
				text.setString("1");
				text.setCharacterSize(24);
				text.setColor(sf::Color::Blue);
				text.getGlobalBounds();
				window.draw(text);
			}
			else if (jeu.grille.grille[x][y] == EtatCase::MORT) {
				sf::Text text;
				text.setString("0");
				text.setCharacterSize(24);
				text.setColor(sf::Color::Red);
				text.getGlobalBounds();
				window.draw(text);
			}

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
		if (jeu.place(x, y, jeu.tour)) {
			if (jeu.tour == EtatCase::X)
				jeu.tour = EtatCase::VIVANT;
			else
				jeu.tour = EtatCase::MORT;
			EtatJeu etat = jeu.checkFin();
			}
		}
	}
}