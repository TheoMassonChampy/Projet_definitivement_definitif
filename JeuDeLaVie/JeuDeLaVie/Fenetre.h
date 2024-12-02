#ifndef FENETRE_H
#define FENETRE_H

#include <SFML/Graphics.hpp>
#include "grille.h"
#include "etat_case.h"
#include "jeu.h"

class Fenetre {
public:
    Fenetre();

    void afficherGrille();
    void click(sf::Event::MouseButtonEvent mouseEvent);

private:
    sf::RenderWindow window;
    Jeu jeu;
};

#endif  // FENETRE_H
