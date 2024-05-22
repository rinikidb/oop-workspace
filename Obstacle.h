#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream> 
#include "DynamicObject.h"
using namespace std;

class Obstacle : public DynamicObject {
private:
    float speed;
    static sf::Texture obstacleTexture;
    sf::Sprite obstacleSprite; 
public:
    Obstacle(sf::Vector2f pos, float spd);

    void move(float deltaTime) override;

    void update(float deltaTime) override;

    void render(sf::RenderWindow& window) override;

    void resizeObstacleSprite();

    sf::FloatRect getBounds() const;
};

#endif // OBSTACLE_H
