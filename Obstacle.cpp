#include <iostream> 
#include "Obstacle.h"

sf::Texture Obstacle::obstacleTexture;

Obstacle::Obstacle(sf::Vector2f pos, float spd) : speed(spd) { 
        position = pos;
        obstacleSprite.setPosition(position.x, position.y);
        resizeObstacleSprite();  

        // Load the background texture
        if (!obstacleTexture.loadFromFile("obstacle.jpeg")) {
            cerr << "Failed to load background image!" << endl;
        }
        obstacleSprite.setTexture(obstacleTexture); 
    }

    void Obstacle::move(float deltaTime){
        position.y += speed * deltaTime;
        obstacleSprite.setPosition(position.x, position.y);
    }

    void Obstacle::update(float deltaTime){
        move(deltaTime);
    }

    void Obstacle::render(sf::RenderWindow& window){
        window.draw(obstacleSprite);
    }

    void Obstacle::resizeObstacleSprite() {
        float targetWidth = 100.0f;
        float targetHeight = 100.0f; 

        sf::Vector2u textureSize = obstacleTexture.getSize();  
        float scaleX = targetWidth / textureSize.x;
        float scaleY = targetHeight / textureSize.y;

        obstacleSprite.setScale(scaleX, scaleY);
    }

    sf::FloatRect Obstacle::getBounds() const { 
        return obstacleSprite.getGlobalBounds();
    }