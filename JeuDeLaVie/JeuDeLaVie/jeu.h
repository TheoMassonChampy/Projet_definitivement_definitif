#pragma once
#include "grille.h"

class Jeu {
public:
	Grille grilledejeu;

	void manager_console() {
		grilledejeu.return_grille();
	}
	
};