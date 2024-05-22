#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "GameObject.h"
#include "StaticObject.h"
#include "DynamicObject.h"
#include "Player.h"
#include "Slicer.h"
#include "Food.h"
#include "Obstacle.h"
#include "PowerUp.h"
#include "LevelManager.h"
#include "UIManager.h"
#include "AudioManager.h"
#include "LevelSelectionScreen.h"
#include "GameOverScreen.h" 
#include "StartScreen.h"
#include "Button.h"


using namespace std;

struct Vector2f { 
    float x, y;
};

enum class GameState {
    StartScreen,
    NameInput,
    LevelSelection,
    Playing,
    GameOver
    
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Food Slasher!");
    window.setFramerateLimit(60);
    int selectedLevel;
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        cerr << "Failed to load font!" << endl;
        return -1;
    }

    StartScreen startScreen(font, { 800, 600 }, "back1.jpg");
    GameState gameState = GameState::StartScreen; 
    //int selectedLevel = 0; 
    Player player("", sf::Vector2f(375, 500));  // Initialize with an empty name

    LevelManager levelManager; 
    AudioManager audioManager;
    UIManager uiManager; 
    Slicer slicer({ 400, 550 }, 1000.0f); 

    vector<Food> foodItems;
    vector<Obstacle> obstacles;
    //float spawnTimer = 0.0f;
    //float spawnInterval = 1000.0f;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { 
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (gameState == GameState::StartScreen) {
              
            StartScreen startScreen(font, { 800, 600 }, "back1.jpg");
            audioManager.backgroundMusicSound.play();
            startScreen.handleEvents(event, window);
            startScreen.render(window);
            
            if (startScreen.isStartClicked()) {
                gameState = GameState::NameInput;
            }
            if (startScreen.isExitClicked()) {
                window.close();
                return 0;
            } 
        } else if (gameState == GameState::NameInput) {
            player.getPlayerName(window, font, startScreen.getWindowSize(), "back1.jpg");  
            //audioManager.backgroundMusicSound.play(); 
            uiManager.displayName(player.getName());

            //gameState = GameState::Playing;  
            gameState = GameState::LevelSelection;// Transition to LevelSelection state
        
        } else if (gameState == GameState::LevelSelection) {
            LevelSelectionScreen levelSelectionScreen({800,600}, "back1.jpg");
            levelSelectionScreen.createLevelButtons(font);
            // Handle level selection 
            selectedLevel = levelSelectionScreen.handleLevelSelection(window);
            levelSelectionScreen.render(window);
            //levelSelectionScreen.render(window);
            levelManager.loadLevel(selectedLevel);
            levelManager.updateSpawnInterval();
            uiManager.displayLevel(selectedLevel);  
            if (selectedLevel > 0) {
                // Load the selected level 
                gameState = GameState::Playing;
            }
    
        } else if (gameState == GameState::Playing) {
            // Load the background texture
            //audioManager.stopBackgroundMusic();
            sf::Texture backgroundTexture; 
            sf::Sprite backgroundSprite;
            if (!backgroundTexture.loadFromFile("back2.jpg")) {
                cerr << "Failed to load background image!" << endl;
            }
            backgroundSprite.setTexture(backgroundTexture);

            sf::Vector2f windowSize = startScreen.getWindowSize(); 

            // Scale the background to fit the window
            sf::Vector2u textureSize = backgroundTexture.getSize();
            sf::Vector2f scaleFactors;
            scaleFactors.x = windowSize.x / textureSize.x;
            scaleFactors.y = windowSize.y / textureSize.y;
            backgroundSprite.setScale(scaleFactors);

            window.draw(backgroundSprite);

                // Handle collisions between slicer and food items
                for (auto& food : levelManager.getFoods()) {
                    sf::FloatRect slicerBounds = slicer.getBounds();
                    sf::FloatRect foodBounds = food.getBounds();

                    if (foodBounds.contains(slicerBounds.left, slicerBounds.top) ||
                        foodBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top) ||
                        foodBounds.contains(slicerBounds.left, slicerBounds.top + slicerBounds.height) ||
                        foodBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top + slicerBounds.height)) {
                        if (food.type == Food::Healthy) {
                            // Play sound effect for healthy food
                            audioManager.scoreDownSound.play();

                            // Remove the food item from the vector
                            // You can replace this with actual sound effects
                            
                            player.decreaseHealth(20);
                            food = levelManager.getFoods().back();
                            levelManager.getFoods().pop_back();
                            
                        } else {
                            // Play sound effect for unhealthy food
                            audioManager.scoreUpSound.play();
                            
                            // Remove the food item from the vector
                            // You can replace this with actual sound effects
                            player.increaseScore(10);
                            food = levelManager.getFoods().back();
                            levelManager.getFoods().pop_back();
                            
                        }
                    }
                }

                for (auto& obstacle : levelManager.getObstacles()){
                    sf :: FloatRect slicerBounds = slicer.getBounds();
                    sf :: FloatRect obstacleBounds = obstacle.getBounds();
                    if(obstacleBounds.contains(slicerBounds.left, slicerBounds.top) || 
                        obstacleBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top) ||
                        obstacleBounds.contains(slicerBounds.left, slicerBounds.top + slicerBounds.height) ||
                        obstacleBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top + slicerBounds.height)){
                            
                            audioManager.scoreDownSound.play(); 
                            player.decreaseHealth(50);
                            obstacle = levelManager.getObstacles().back();
                            levelManager.getObstacles().pop_back();
                            
                    }
                }

                for (auto& powerUp : levelManager.getPowerUps()) {
                    sf :: FloatRect slicerBounds = slicer.getBounds();
                    sf :: FloatRect powerUpBounds = powerUp.getBounds(); 
                    if (powerUpBounds.contains(slicerBounds.left, slicerBounds.top) ||
                            powerUpBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top) ||
                            powerUpBounds.contains(slicerBounds.left, slicerBounds.top + slicerBounds.height) ||
                            powerUpBounds.contains(slicerBounds.left + slicerBounds.width, slicerBounds.top + slicerBounds.height)) {
                                
                                audioManager.scoreUpSound.play();
                                player.setHealth(100);
                                powerUp = levelManager.getPowerUps().back();
                                levelManager.getPowerUps().pop_back();
                                
                    }
                }


            // Update player's name and UI elements
            uiManager.displayName(player.getName());
            uiManager.displayScore(player.getScore());
            uiManager.displayHealth(player.getHealth());
            
            // Render UI
            uiManager.render(window);

            float deltaTime = clock.restart().asSeconds();

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            slicer.updateShapePosition(mousePos);
            /*
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            slicer.moveTowards(static_cast<sf::Vector2f>(mousePos));*/

            /*
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                slicer.moveLeft();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                slicer.moveRight();
            }
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                slicer.moveUp();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                slicer.moveDown();
            }
            */

            //levelManager.spawnFoodRandomly();  // Spawn food randomly (consider adding a timer for better control)
            levelManager.update(deltaTime);
            slicer.update(deltaTime);   

            // Update the UI with the player's current state
            uiManager.displayScore(player.getScore());
            uiManager.displayHealth(player.getHealth());
            uiManager.displayLevel(selectedLevel);  // Assuming level 1 for now; update as needed

            levelManager.render(window);
            slicer.render(window);
            //player.render(window);

            // Check if health is zero and transition to Game Over state
            if (!player.isAlive()) {
                    gameState = GameState::GameOver;
                    
                    audioManager.backgroundMusicSound.stop();

                    audioManager.gameOverMusicSound.play();
                    audioManager.gameOverMusicSound.stop();
                    /*
                    // Declare GameOverScreen object
                    GameOverScreen gameOverScreen(font, { 800, 600 }, player.getScore(), "back1.jpg");
                    gameOverScreen.handleEvents(event, window);
                    */
            }

        } else if(gameState == GameState::GameOver) {

                audioManager.backgroundMusicSound.stop();

                audioManager.gameOverMusicSound.play();
                audioManager.gameOverMusicSound.stop();
                // Declare GameOverScreen object
                GameOverScreen gameOverScreen(font, { 800, 600 }, player.getScore(), "back1.jpg");
                // Handle events for Game Over screen
                gameOverScreen.handleEvents(event, window);
                // If OK button clicked, revert to StartScreen state
                if (gameOverScreen.isOKClicked()) {
                    gameState = GameState::StartScreen;
                    audioManager.backgroundMusicSound.play();
                    // Reset player's health and score
                    player = Player("", sf::Vector2f(375, 500));
                }
                audioManager.gameOverMusicSound.play();
                audioManager.gameOverMusicSound.stop();
                gameOverScreen.render(window);
                

        }
        //window.clear();
        window.display();
    }

    return 0;
} 