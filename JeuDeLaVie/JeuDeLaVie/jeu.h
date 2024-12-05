#pragma once
#include "grille.h"

class Jeu {
public:
	Grille grilledejeu;

	int nombre_voisin(int location);
	void manager_console();
};