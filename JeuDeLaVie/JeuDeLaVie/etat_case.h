#pragma once
enum class EtatCase {
	BLOC_VIVANT,    // La case est bloqu�e positivement
	BLOC_MORT,		// La case est bloqu�e n�gativement
	MORT,			// La case est occup�e par "0"
	VIVANT			// La case est occup�e par "1"
};