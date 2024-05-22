//LevelSelectionScreen.h
#ifndef LEVELSELECTIONSCREEN_H
#define LEVELSELECTIONSCREEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h" 
using namespace std;

class LevelSelectionScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2f windowSize;
    std::vector<Button> buttons;

public:
    LevelSelectionScreen(sf::Vector2f windowSize, const std::string& backgroundFilename);

    void createLevelButtons(sf::Font& font);
        
    
    int handleLevelSelection(sf::RenderWindow& window);
        
    void render(sf::RenderWindow& window);
};
#endif 