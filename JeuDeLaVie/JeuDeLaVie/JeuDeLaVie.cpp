#include <iostream>
#include "fenetre.h"
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
	return 0;
}