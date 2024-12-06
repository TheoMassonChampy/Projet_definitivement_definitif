#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>

class GameScreen {
private:
    std::vector<std::vector<bool>> grid;
    sf::RectangleShape rectangle_separation;
    sf::RectangleShape home_button;
    sf::RectangleShape play_button;
    sf::Text jeu_de_la_vie;
    sf::Text instructions;
    sf::Text home_text;
    sf::Text play_arrow;
    sf::Font font;
    bool isPlaying;

    const int cellSize = 30;

public:
    GameScreen(sf::RenderWindow& window);

    bool handleEvent(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void updateGame();
    int countNeighbors(int x, int y);
    void updateGrid();
};

#endif