#include "jeu.h"
#include "grille.h"

int Jeu::nombre_voisin(int location) {
	int nb_voisin = 0;
	if (location == 0) { //en haut � gauche
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location == grilledejeu.largeur - 1) { //en haut � droite
		if ((grilledejeu.grille[location - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location == (grilledejeu.largeur * grilledejeu.hauteur) - grilledejeu.largeur) { //en bas � gauche
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location == (grilledejeu.largeur * grilledejeu.hauteur) - 1) { // en bas � droite
		if ((grilledejeu.grille[location - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location % grilledejeu.largeur == 0 && location != 0 && location == (grilledejeu.largeur * grilledejeu.hauteur) - grilledejeu.largeur) { //Premi�re colonne (sans 0 et case en bas � gauche)
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if ((location % grilledejeu.largeur) - 1 == 0) { //Derni�re colonne (� droite)
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location < grilledejeu.largeur) { //Premi�re ligne
		if ((grilledejeu.grille[location - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else if (location > (grilledejeu.largeur * grilledejeu.hauteur) - grilledejeu.largeur) {
		if (grilledejeu.grille[location - 1] == EtatCase::VIVANT) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	else {
		if ((grilledejeu.grille[location - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location - grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur - 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + grilledejeu.largeur + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
		if ((grilledejeu.grille[location + 1] == EtatCase::VIVANT) || (grilledejeu.grille[location + 1] == EtatCase::BLOC_VIVANT)) { nb_voisin += 1; }
	}
	return nb_voisin;
}

void Jeu::manager_console() {
	std::cout << "Chargement du fichier de jeu ..." << std::endl;
	grilledejeu.Chargement_grille_fichier();
	std::cout << "Chargement r�ussi ! Grille d�finie." << std::endl;
	grilledejeu.affiche_grille(grilledejeu.grille_vers_nombre());
	for (int i = 0; i < grilledejeu.largeur; i++) {
		int voisins = nombre_voisin(i);
		if ((grilledejeu.grille[i] != EtatCase::BLOC_MORT) || (grilledejeu.grille[i] != EtatCase::BLOC_VIVANT)) {
			if (voisins == 3) {
				if (grilledejeu.grille[i] == EtatCase::MORT) { grilledejeu.grille[i] == EtatCase::VIVANT; }
			}
			else if ((voisins < 2) || (voisins > 3)) {
				if (grilledejeu.grille[i] == EtatCase::VIVANT) { grilledejeu.grille[i] == EtatCase::MORT; }
			}
		}
	}
}