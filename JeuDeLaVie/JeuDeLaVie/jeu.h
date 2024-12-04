#pragma once
#include "grille.h"

class Jeu {
public:
	Grille grilledejeu;

	void manager_console() {
		grilledejeu.Chargement_grille_fichier();
		//grilledejeu.return_grille();
	}
	
};