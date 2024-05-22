#include <SFML/Graphics.hpp>
#include "Slicer.h"

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Slicer Test");

    // Create a slicer object
    Slicer slicer(sf::Vector2f(400, 300), 200.0f); // Initial position at center of window, speed of 200 units/second

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Update slicer position based on mouse movement
            if (event.type == sf::Event::MouseMoved) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                slicer.updateShapePosition(mousePos);
            }
        }

        // Clear the window with a black color
        window.clear(sf::Color::Black);

        // Update and render the slicer
        slicer.update(0.0f); // deltaTime is not used in this test
        slicer.render(window);

        // Display the window contents
        window.display();
    }

    return 0;
}