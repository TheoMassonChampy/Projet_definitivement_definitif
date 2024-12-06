#include <iostream>
#include "game_screen.h"
#include "main_menu.h"
#include <stdio.h>

int main()
{
	int answer;
	std::cout << "<<<Jeu de la Vie !>>>\nSouhaitez vous utiliser le mode console (1) ou le mode graphique (2) ?\n>> ";
	std::cin >> answer;
	if (answer == 1) {
		Jeu instance_jeu;
		instance_jeu.manager_console(); 
	}
	else if (answer == 2) {
		Fenetre f;
	}
	else {
		std::cout << "Entrée impossible ... fermeture du programme ...";
	}
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Fenêtre test");

    MainMenu menu(window);
    GameScreen gameScreen(window);

    bool inMenu = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (inMenu) {
                if (menu.handleEvent(event, window)) {
                    inMenu = false;
                }
            }
            else {
                if (gameScreen.handleEvent(event, window)) {
                    inMenu = true;
                }
            }
        }

        if (inMenu) {
            menu.draw(window);
        }
        else {
            gameScreen.draw(window);
        }
    }

    return 0;
}