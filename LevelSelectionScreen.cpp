#include <iostream>
#include "LevelSelectionScreen.h"

LevelSelectionScreen::LevelSelectionScreen(sf::Vector2f windowSize, const std::string& backgroundFilename) {

    this->windowSize = windowSize;

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

void LevelSelectionScreen::createLevelButtons(sf::Font& font) {
    sf::Vector2f buttonPosition1(windowSize.x / 2 - 100, windowSize.y / 2 - 90); // Adjust positions as needed
    sf::Vector2f buttonPosition2(windowSize.x / 2 - 100, windowSize.y / 2 - 20); 
    sf::Vector2f buttonPosition3(windowSize.x / 2 - 100, windowSize.y / 2 + 50);

    buttons.emplace_back(font, "Level 1", buttonPosition1);
    buttons.emplace_back(font, "Level 2", buttonPosition2);
    buttons.emplace_back(font, "Level 3", buttonPosition3); 
}

int LevelSelectionScreen::handleLevelSelection(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (auto& button : buttons) { 
                button.handleClick(mousePos);
                if (button.wasClicked()) {
                    if (button.getText() == "Level 1") {
                        return 1;
                    } else if (button.getText() == "Level 2") {
                        return 2;
                    } else if (button.getText() == "Level 3") {
                        return 3;
                    }
                }
            }
        }

    } 
    return 0; // No level selected
}

void LevelSelectionScreen::render(sf::RenderWindow& window) {
    // Draw the background
    window.draw(backgroundSprite);

    // Draw the buttons
    for (auto& button : buttons) {
        button.render(window); 
    }
}

