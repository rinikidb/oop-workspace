#ifndef UIMANAGER_H
#define UIMANAGER_H

#include <SFML/Graphics.hpp>

#include "StaticObject.h"

class UIManager : public StaticObject {
private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text healthText;
    sf::Text levelText;
    sf::Text nameText;

public:
    UIManager();
    int loadLevel(int level);
    void displayScore(int score);
    void displayHealth(int health);
    void displayLevel(int level);
    void displayName(const std::string& name);
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void display() override;
};

#endif // UIMANAGER_H
