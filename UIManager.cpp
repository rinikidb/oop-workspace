#include <iostream>
#include "UIManager.h"

using namespace std;

UIManager::UIManager() {
        if (!font.loadFromFile("font.ttf")) {
            cerr << "Failed to load font!" << endl;
        }
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, 10);

        healthText.setFont(font);
        healthText.setCharacterSize(20);
        healthText.setFillColor(sf::Color::White);
        healthText.setPosition(10, 40);

        levelText.setFont(font);
        levelText.setCharacterSize(20);
        levelText.setFillColor(sf::Color::White);
        levelText.setPosition(10, 70);

        nameText.setFont(font);
        nameText.setCharacterSize(20);
        nameText.setFillColor(sf::Color::White);
        nameText.setPosition(10, 100);
    }
    int UIManager::loadLevel(int level) { 
        int currentLevel = level;
        return currentLevel;  
        
    }

    void UIManager::displayScore(int score) {
        scoreText.setString("Score: " + to_string(score));
    }

    void UIManager::displayHealth(int health) {
        healthText.setString("Health: " + to_string(health));
    }

    void UIManager::displayLevel(int level) {
        levelText.setString("Level: " + to_string(loadLevel(level)));
    }

    void UIManager::displayName(const string& name) {
        nameText.setString("Player: " + name);
    }
 
    void UIManager::update(float deltaTime){}

    void UIManager::render(sf::RenderWindow& window) {
        window.draw(scoreText);
        window.draw(healthText);  
        window.draw(levelText);
        window.draw(nameText); 
    }

    void UIManager::display() {}