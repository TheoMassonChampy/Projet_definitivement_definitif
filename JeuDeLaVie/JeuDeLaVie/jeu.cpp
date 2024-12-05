#include "jeu.h"
#include "grille.h"

int Jeu::nombre_voisin(int location) {
	int nb_voisin = 0;
	if (location == 0) {
		if (grilledejeu.grille[location + 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
	}
	else if (location == grilledejeu.largeur - 1) {
		if (grilledejeu.grille[location - 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
	}
	else if (location == (grilledejeu.largeur * grilledejeu.hauteur) - grilledejeu.largeur) {
		if (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location + 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
	}
	else if (location == (grilledejeu.largeur * grilledejeu.hauteur) - 1) {
		if (grilledejeu.grille[location - 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
		if (grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::VIVANT) {
			nb_voisin += 1;
		}
	}
	else if () {

	}
	return nb_voisin;
}

void Jeu::manager_console() {
	std::cout << "Chargement du fichier de jeu ..." << std::endl;
	grilledejeu.Chargement_grille_fichier();
	std::cout << "Chargement réussi ! Grille définie." << std::endl;
	grilledejeu.affiche_grille(grilledejeu.grille_vers_nombre());
}