#include <iostream> 
#include "Button.h"

using namespace std;

Button::Button(sf::Font& font, string buttonText, sf::Vector2f pos) : isClicked(false) {
        position = pos;
        shape.setSize(sf::Vector2f(200, 50));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position.x, position.y);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(position.x + 20, position.y + 10);  // Adjust text position for centering
    }

    void Button::centerText() { 
        // Calculate the center of the button
        sf::Vector2f buttonCenter = position + sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2);

        // Calculate the position to center the text within the button
        sf::Vector2f textPosition;
        textPosition.x = buttonCenter.x - text.getLocalBounds().width / 2;
        textPosition.y = buttonCenter.y - text.getLocalBounds().height / 2;

        // Set the position of the text
        text.setPosition(textPosition);
    }  

    void Button::handleClick(sf::Vector2i mousePos) {
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            isClicked = true;
        }
    }

    bool Button::wasClicked() const {
        return isClicked;
    }

    std::string Button::getText() const {
        return text.getString();
    }

    void Button::update(float deltaTime) {
        // No need to update button
    }

    void Button::render(sf::RenderWindow& window)  {
        window.draw(shape);
        window.draw(text);
    }