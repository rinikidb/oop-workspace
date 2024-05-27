#include <iostream>
#include "Player.h"

Player::Player(string playerName, sf::Vector2f pos) : name(playerName), score(0), health(100) {
        position = pos;
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Green); 
        shape.setPosition(position.x, position.y);
    } 

    void Player::setName(string playerName) { name = playerName; }
    string Player::getName() const { return name; }
    void Player::increaseScore(int amount) { score += amount; }
    void Player::decreaseHealth(int amount) { health -= amount; }
    bool Player::isAlive() { return health > 0; }
    int Player::getHealth() { return health; }
    void Player::setHealth(int health){
        this->health = health;  
    }
    int Player::getScore() { return score; }

    void Player::move(float deltaTime) {   
        position.y += 0.0f * deltaTime;
        backgroundSprite.setPosition(position.x, position.y); 
    } 

    void Player::update(float deltaTime) {
        move(deltaTime);
    }

    void Player::render(sf::RenderWindow& window) {
        window.draw(shape); 
    }

    void Player::display() {
        cout << "Player: " << name << " Score: " << score << " Health: " << health << endl;
    }

    sf::FloatRect Player::getBounds() const {
        return shape.getGlobalBounds();
    }


    void Player::getPlayerName(sf::RenderWindow& window, sf::Font& font, sf::Vector2f windowSize) {

        // Load the background texture   
        if (!backgroundTexture.loadFromFile("back1.jpg")) {
            cerr << "Failed to load background image!" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);

        // Scale the background to fit the window
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x;
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);

        sf::Text prompt("Enter your name: ", font, 24);
        prompt.setPosition(200, 250);
        prompt.setFillColor(sf::Color::White);

        sf::Text playerNameText("", font, 24);
        playerNameText.setPosition(200, 300);
        playerNameText.setFillColor(sf::Color::White);

        // Calculate the center of the window
        float centerX = windowSize.x / 2;

        // Calculate the center of the text based on its width
        sf::FloatRect promptBounds = prompt.getLocalBounds();
        float promptCenterX = centerX - promptBounds.width / 2;

        sf::FloatRect playerNameTextBounds = playerNameText.getLocalBounds();
        float playerNameTextCenterX = centerX - promptBounds.width / 2;

        // Set the text positions
        prompt.setPosition(promptCenterX, 250);
        playerNameText.setPosition(playerNameTextCenterX, 300);

        std::string playerName;
        bool nameEntered = false;

        while (window.isOpen() && !nameEntered) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                else if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode == '\b') { // Handle backspace
                        if (!playerName.empty()) {
                            playerName.pop_back();
                        }
                    }
                    else if (event.text.unicode == '\r') { // Handle enter key
                        if (!playerName.empty()) {
                            nameEntered = true;
                        }
                    }
                    else if (event.text.unicode < 128) { // Handle other characters
                        playerName += static_cast<char>(event.text.unicode);
                    }
                    playerNameText.setString(playerName);
                }
            }

            window.clear();
            window.draw(backgroundSprite);
            window.draw(prompt);
            window.draw(playerNameText);
            window.display(); 
        }

        setName(playerName);
    }