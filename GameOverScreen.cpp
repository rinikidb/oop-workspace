#include <iostream>
#include "GameOverScreen.h"

using namespace std;  

GameOverScreen::GameOverScreen(sf::Font& font, sf::Vector2f windowSize, int score, const std::string& backgroundFilename)
        : okButton(font, "OK", { windowSize.x / 2 - 100, windowSize.y / 2 + 20 }) {
        okButton.centerText(); 
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(windowSize.x / 2 - 100, windowSize.y / 2 - 50);
        scoreText.setString("Score: " + std::to_string(score));

        // Load the background texture
        if (!backgroundTexture.loadFromFile(backgroundFilename)) {
            cerr << "Failed to load background image!" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);

        // Scale the background to fit the window
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x;
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);
        
    }

    void GameOverScreen::handleEvents(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            okButton.handleClick(sf::Mouse::getPosition(window));
        }
    }

    bool GameOverScreen::isOKClicked() const {
        return okButton.wasClicked();
    }

    void GameOverScreen::render(sf::RenderWindow& window) {
        window.draw(backgroundSprite);
        window.draw(scoreText);
        okButton.render(window);
        
    }