#include <iostream> 
#include "StartScreen.h"

StartScreen::StartScreen(sf::Font& font, sf::Vector2f windowSize, const std::string& backgroundFilename)
    : startClicked(false), exitClicked(false) {
    // Load the background texture
    if (!backgroundTexture.loadFromFile(backgroundFilename)) {
        std::cerr << "Failed to load background image!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTexture);

    // Scale the background to fit the window  
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x;
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);

    // Create buttons
    Button startButton(font, "Start Game", { windowSize.x / 2 - 100, windowSize.y / 2 - 60 });
    Button exitButton(font, "Exit", { windowSize.x / 2 - 100, windowSize.y / 2 + 20 });
    buttons.push_back(startButton);
    buttons.push_back(exitButton);
}

void StartScreen::handleEvents(sf::Event event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (auto& button : buttons) {
            button.handleClick(mousePos);
        }
    }

    for (const auto& button : buttons) {
        if (button.wasClicked() && button.getText() == "Start Game") {
            startClicked = true;
        }
        else if (button.wasClicked() && button.getText() == "Exit") {
            exitClicked = true;
        }
    }
}

void StartScreen::render(sf::RenderWindow& window) {
    // Draw the background
    window.draw(backgroundSprite);

    // Draw the buttons
    for (auto& button : buttons) {
        button.render(window);
    }
}

sf::Vector2f StartScreen::getWindowSize(){  
            return windowSize; 
} 

bool StartScreen::isStartClicked() const {
    return startClicked;
}

bool StartScreen::isExitClicked() const {
    return exitClicked;
}
 
