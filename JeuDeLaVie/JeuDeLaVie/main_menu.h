#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window);
    bool handleEvent(sf::Event& event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape rectangle_play;
    sf::RectangleShape rectangle_quitter;
    sf::Text title;
    sf::Text play_text;
    sf::Text quit_text;
    sf::Font font;

    std::vector<sf::CircleShape> stars;
    const int cellSize = 20;

    void generateStars(const sf::Vector2u& windowSize, size_t numStars);
};

#endif
