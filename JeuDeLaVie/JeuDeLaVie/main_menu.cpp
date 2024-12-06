#include "main_menu.h"
#include <stdexcept>

MainMenu::MainMenu(sf::RenderWindow& window) {
    rectangle_play.setSize(sf::Vector2f(250, 50));
    rectangle_play.setPosition((window.getSize().x - rectangle_play.getLocalBounds().width) / 2, 450);
    rectangle_play.setFillColor(sf::Color::White);

    rectangle_quitter.setSize(sf::Vector2f(250, 50));
    rectangle_quitter.setPosition((window.getSize().x - rectangle_quitter.getLocalBounds().width) / 2, 550);
    rectangle_quitter.setFillColor(sf::Color::White);

    if (!font.loadFromFile("arial.ttf")) {
        throw std::runtime_error("Impossible de charger la police.");
    }

    title.setFont(font);
    title.setString("JEU DE LA VIE");
    title.setCharacterSize(60);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);
    title.setPosition((window.getSize().x - title.getLocalBounds().width) / 2, 350);

    play_text.setFont(font);
    play_text.setString("PLAY");
    play_text.setCharacterSize(40);
    play_text.setFillColor(sf::Color::Black);
    play_text.setStyle(sf::Text::Bold);

    sf::FloatRect textBounds = play_text.getLocalBounds();
    sf::Vector2f rectPosition = rectangle_play.getPosition();
    sf::Vector2f rectSize = rectangle_play.getSize();
    play_text.setPosition(
        rectPosition.x + (rectSize.x - textBounds.width) / 2 - textBounds.left,
        rectPosition.y + (rectSize.y - textBounds.height) / 2 - textBounds.top
    );

    quit_text.setFont(font);
    quit_text.setString("QUIT");
    quit_text.setCharacterSize(40);
    quit_text.setFillColor(sf::Color::Black);
    quit_text.setStyle(sf::Text::Bold);

    sf::FloatRect quitBounds = quit_text.getLocalBounds();
    sf::Vector2f quitPosition = rectangle_quitter.getPosition();
    sf::Vector2f quitSize = rectangle_quitter.getSize();
    quit_text.setPosition(
        quitPosition.x + (quitSize.x - quitBounds.width) / 2 - quitBounds.left,
        quitPosition.y + (quitSize.y - quitBounds.height) / 2 - quitBounds.top
    );

    generateStars(window.getSize(), 200);
}

bool MainMenu::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (rectangle_play.getGlobalBounds().contains(
            static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
            return true;
        }

        if (rectangle_quitter.getGlobalBounds().contains(
            static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
            window.close();
        }
    }
    return false;
}

void MainMenu::draw(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);

    for (const auto& star : stars) {
        window.draw(star);
    }

    window.draw(rectangle_play);
    window.draw(title);
    window.draw(play_text);
    window.draw(rectangle_quitter);
    window.draw(quit_text);

    window.display();
}

void MainMenu::generateStars(const sf::Vector2u& windowSize, size_t numStars) {
    stars.clear();
    for (size_t i = 0; i < numStars; ++i) {
        sf::CircleShape star(2);
        star.setFillColor(sf::Color::White);

        float x = static_cast<float>(rand() % windowSize.x);
        float y = static_cast<float>(rand() % windowSize.y);
        star.setPosition(x, y);

        stars.push_back(star);
    }
}
