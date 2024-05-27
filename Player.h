#ifndef PLAYER_H
#define PLAYER_H

#include "StaticObject.h"
using namespace std; 

// Player Class . h
class Player : public StaticObject {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    string name;
    int score;
    int health;
    sf::RectangleShape shape;

public:
    Player(string playerName, sf::Vector2f pos);
     

    void setName(string playerName);
    string getName() const;
    void increaseScore(int amount);
    void decreaseHealth(int amount);
    bool isAlive();
    int getHealth();
    void move(float deltaTime); 
    void setHealth(int health);
        
    int getScore();

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;
      

    void display() override;
        

    sf::FloatRect getBounds() const;
    void getPlayerName(sf::RenderWindow& window, sf::Font& font, sf::Vector2f windowSize);
};
#endif // PLAYER_H
