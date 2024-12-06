#include "game_screen.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "game_screen.h"

GameScreen::GameScreen(sf::RenderWindow& window) {
    int rows = 900 / cellSize;
    int cols = 850 / cellSize;
    grid.resize(rows, std::vector<bool>(cols, true));

    rectangle_separation.setSize(sf::Vector2f(350, rows * cellSize));
    rectangle_separation.setPosition(0, 0);
    rectangle_separation.setFillColor(sf::Color::Black);

    home_button.setSize(sf::Vector2f(150, 50));
    home_button.setPosition(100, 800);
    home_button.setFillColor(sf::Color::White);

    play_button.setSize(sf::Vector2f(150, 50));
    play_button.setPosition(100, 725);
    play_button.setFillColor(sf::Color::White);

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Impossible de charger la police.");
    }

    jeu_de_la_vie.setFont(font);
    jeu_de_la_vie.setString("Jeu de la vie!");
    jeu_de_la_vie.setCharacterSize(50);
    jeu_de_la_vie.setFillColor(sf::Color::White);
    jeu_de_la_vie.setStyle(sf::Text::Bold);
    jeu_de_la_vie.setPosition(20, 50);

    instructions.setFont(font);
    instructions.setString("Cliquez sur les cellules \nde votre choix puis cliquez \nsur le rectangle '>' ci dessous\npour commencer le jeu.");
    instructions.setCharacterSize(20);
    instructions.setFillColor(sf::Color::White);
    instructions.setStyle(sf::Text::Bold);
    instructions.setPosition(20, 250);

    home_text.setFont(font);
    home_text.setString("HOME");
    home_text.setCharacterSize(30);
    home_text.setFillColor(sf::Color::Black);
    home_text.setStyle(sf::Text::Bold);

    play_arrow.setFont(font);
    play_arrow.setString(">");
    play_arrow.setCharacterSize(50);
    play_arrow.setFillColor(sf::Color::Black);
    play_arrow.setStyle(sf::Text::Bold);

    sf::FloatRect homeTextBounds = home_text.getLocalBounds();
    sf::Vector2f homeButtonPosition = home_button.getPosition();
    sf::Vector2f homeButtonSize = home_button.getSize();
    home_text.setPosition(
        homeButtonPosition.x + (homeButtonSize.x - homeTextBounds.width) / 2 - homeTextBounds.left,
        homeButtonPosition.y + (homeButtonSize.y - homeTextBounds.height) / 2 - homeTextBounds.top
    );

    sf::FloatRect playArrowBounds = play_arrow.getLocalBounds();
    sf::Vector2f playButtonPosition = play_button.getPosition();
    sf::Vector2f playButtonSize = play_button.getSize();
    play_arrow.setPosition(
        playButtonPosition.x + (playButtonSize.x - playArrowBounds.width) / 2 - playArrowBounds.left,
        playButtonPosition.y + (playButtonSize.y - playArrowBounds.height) / 2 - playArrowBounds.top
    );

}


bool GameScreen::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::Closed) {
        return false;
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (play_button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            isPlaying = !isPlaying;
        }

        if (!isPlaying) {
            int x = (mousePos.x - 350) / cellSize;
            int y = mousePos.y / cellSize;
            if (x >= 0 && x < grid[0].size() && y >= 0 && y < grid.size()) {
                grid[y][x] = !grid[y][x];
            }
        }
    }

    return false;
}

void GameScreen::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    window.draw(rectangle_separation);

    for (int y = 0; y < grid.size(); ++y) {
        for (int x = 0; x < grid[y].size(); ++x) {
            sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));
            cell.setPosition(350 + x * cellSize, y * cellSize);
            cell.setFillColor(grid[y][x] ? sf::Color::Black : sf::Color::White);
            cell.setOutlineColor(sf::Color::White);
            cell.setOutlineThickness(1);
            window.draw(cell);
        }
    }

    window.draw(home_button);
    window.draw(play_button);
    window.draw(home_text);
    window.draw(jeu_de_la_vie);
    window.draw(instructions);
    window.draw(play_arrow);

    if (isPlaying) {
        updateGrid();
        sf::sleep(sf::milliseconds(200));
    }

    window.display();
}

void GameScreen::updateGrid() {
    std::vector<std::vector<bool>> newGrid = grid;

    int rows = grid.size();
    int cols = grid[0].size();

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            int liveNeighbors = 0;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;

                    int ny = y + dy;
                    int nx = x + dx;

                    if (nx >= 0 && nx < cols && ny >= 0 && ny < rows && grid[ny][nx]) {
                        liveNeighbors++;
                    }
                }
            }

            if (grid[y][x]) {
                newGrid[y][x] = (liveNeighbors == 2 || liveNeighbors == 3);
            }
            else {
                newGrid[y][x] = (liveNeighbors == 3);
            }
        }
    }
    grid = newGrid;
}