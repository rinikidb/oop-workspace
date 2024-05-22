#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"

class StartScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2f windowSize;
    std::vector<Button> buttons;
    bool startClicked;
    bool exitClicked;

public:
    StartScreen(sf::Font& font, sf::Vector2f windowSize, const std::string& backgroundFilename);
    void handleEvents(sf::Event event, sf::RenderWindow& window);
    sf::Vector2f getWindowSize();
    void render(sf::RenderWindow& window);
    bool isStartClicked() const;
    bool isExitClicked() const;
};

#endif // STARTSCREEN_H
