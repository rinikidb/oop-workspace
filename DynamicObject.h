#ifndef DYNAMICOBJECT_H
#define DYNAMICOBJECT_H

#include "GameObject.h" 

class DynamicObject : public GameObject {
public:
    sf::Vector2f velocity;
    virtual void move(float deltaTime) = 0;
};

#endif // DYNAMICOBJECT_H
