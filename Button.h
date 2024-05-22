#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

#include "GameObject.h" 


class Button : public GameObject {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isClicked;

public:
    Button(sf::Font& font, std::string buttonText, sf::Vector2f pos);
    void handleClick(sf::Vector2i mousePos);
    bool wasClicked() const;
    void centerText(); 
    std::string getText() const;
    void render(sf::RenderWindow& window);
    void update(float deltaTime);

};

#endif // BUTTON_H
