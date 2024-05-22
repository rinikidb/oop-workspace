#include <iostream>
#include "Slicer.h"
#include <cmath> 

using namespace std; 

Slicer::Slicer(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        shape.setRadius(5); // Set radius for the circle slicer
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position.x - shape.getRadius(), position.y - shape.getRadius());
    }
    
    void Slicer::moveTowards(sf::Vector2f target) {
        sf::Vector2f direction = target - position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (distance > 0) {
            direction /= distance;
            position += direction * speed;
        }
    }

    sf::Vector2f Slicer::getPosition() { return position; }

    void Slicer::move(float deltaTime) {
        position.y += 0.0f * deltaTime;
        shape.setPosition(position.x, position.y);
    } 

    void Slicer::update(float deltaTime) {   
        shape.setPosition(position.x, position.y);
    }

    void Slicer::render(sf::RenderWindow& window) {
        window.draw(shape);
    }

    sf::FloatRect Slicer::getBounds() const {
        return shape.getGlobalBounds();
    }

    void Slicer::updateShapePosition(sf::Vector2i mousePos) {
        position = static_cast<sf::Vector2f>(mousePos); // Set the slicer's position to match mouse position
        shape.setPosition(position.x - shape.getRadius(), position.y - shape.getRadius()); // Adjust position of the circle shape
    }