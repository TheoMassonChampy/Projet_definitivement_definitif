#pragma once
enum class EtatCase {
	BLOC_VIVANT,    // La case est bloquée positivement
	BLOC_MORT,		// La case est bloquée négativement
	MORT,			// La case est occupée par "0"
	VIVANT			// La case est occupée par "1"
};