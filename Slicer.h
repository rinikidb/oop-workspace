#ifndef SLICER_H
#define SLICER_H

#include "DynamicObject.h"

// Slicer Class . h
class Slicer : public DynamicObject {
private:
    float speed;
    //sf::RectangleShape shape
    sf :: CircleShape shape;
public:
  
    Slicer(sf::Vector2f pos, float spd);
      
    void moveTowards(sf::Vector2f target);
        
    sf::Vector2f getPosition();

    void move(float deltaTime) override;
     
    void update(float deltaTime) override;    
        
    void render(sf::RenderWindow& window) override;
        

    sf::FloatRect getBounds() const;
       
    void updateShapePosition(sf::Vector2i mousePos);
}; 

#endif // SLICER_H
