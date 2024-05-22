#include <iostream> 
#include "PowerUp.h"
using namespace std;

sf::Texture PowerUp :: powerUpTexture;

PowerUp::PowerUp(sf::Vector2f pos, float spd) : speed(spd){
    position = pos;
    powerUpSprite.setPosition(position.x,position.y);
    resizePowerUpSprite();

    // Load the background texture
            if (!powerUpTexture.loadFromFile("powerUp.jpeg")) {
                cerr << "Failed to load background image!" << endl;
            }
            powerUpSprite.setTexture(powerUpTexture); 
}

void PowerUp::move(float deltaTime) {
    position.y += speed * deltaTime;
    powerUpSprite.setPosition(position.x, position.y);
}

void PowerUp::update(float deltaTime) {
    move(deltaTime);
}

void PowerUp::render(sf::RenderWindow& window) {
    window.draw(powerUpSprite);
}

void PowerUp::resizePowerUpSprite() {
    float targetWidth = 100.0f;
    float targetHeight = 100.0f; 

    sf::Vector2u textureSize = powerUpTexture.getSize();  
    float scaleX = targetWidth / textureSize.x;
    float scaleY = targetHeight / textureSize.y;

    powerUpSprite.setScale(scaleX, scaleY);
}


sf::FloatRect PowerUp::getBounds() const {
    return powerUpSprite.getGlobalBounds();
}