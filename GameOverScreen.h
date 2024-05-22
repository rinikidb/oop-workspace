#ifndef GAMEOVERSCREEN_H
#define GAMEOVERSCREEN_H

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h" 

class GameOverScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text scoreText;
    Button okButton;

public:
    GameOverScreen(sf::Font& font, sf::Vector2f windowSize, int score, const std::string& backgroundFilename);

    void handleEvents(sf::Event event, sf::RenderWindow& window);
         

    bool isOKClicked() const;
       

    void render(sf::RenderWindow& window);
};

#endif 