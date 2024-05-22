#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "LevelSelectionScreen.h" 

int main() {
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Level Selection Test");

    // Load font (make sure you have a font file available)
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
        return -1;
    }

    // Create the LevelSelectionScreen
    LevelSelectionScreen levelSelectionScreen(sf::Vector2f(800, 600), "background.jpg");
    levelSelectionScreen.createLevelButtons(font);

    while (window.isOpen()) {
        int selectedLevel = levelSelectionScreen.handleLevelSelection(window);

        if (selectedLevel > 0) {
            std::cout << "Selected Level: " << selectedLevel << std::endl;
            // You can add code here to load the selected level
            break; // Exit loop after level selection
        }

        window.clear();
        levelSelectionScreen.render(window);
        window.display();
    }

    return 0;
}