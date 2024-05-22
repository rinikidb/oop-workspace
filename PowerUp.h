#ifndef POWERUP_H
#define POWERUP_H

#include "DynamicObject.h"

// PowerUp Class . h
class PowerUp : public DynamicObject {
private:
    float speed;
    static sf::Texture powerUpTexture;
    sf::Sprite powerUpSprite; 
public:
    PowerUp(sf::Vector2f pos, float spd);
    
    void move(float deltaTime) override;
            

    void update(float deltaTime) override;
           

     void render(sf::RenderWindow& window) override;
           
     void resizePowerUpSprite();
            
     sf::FloatRect getBounds() const;
      
};

#endif // POWERUP_H
