#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Vector2f {
    float x, y;
};

// Abstract Base Class
class GameObject {
public:
    sf::Vector2f position;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};

class Button : public GameObject {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isClicked;

public:
    Button(sf::Font& font, string buttonText, sf::Vector2f pos) : isClicked(false) {
        position = pos;
        shape.setSize(sf::Vector2f(200, 50));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position.x, position.y);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(position.x + 20, position.y + 10);  // Adjust text position for centering
    }

    void handleClick(sf::Vector2i mousePos) {
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            isClicked = true;
        }
    }

    bool wasClicked()const {
        return isClicked;
    }

    std::string getText() const {
        return text.getString();
    }

    void update(float deltaTime) override {
        // No need to update button
    }

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
        window.draw(text);
    }
};

class StartScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    std::vector<Button> buttons;
    bool startClicked;
    bool exitClicked;

public:
    StartScreen(sf::Font& font, sf::Vector2f windowSize)
        : startClicked(false), exitClicked(false) {
        if (!backgroundTexture.loadFromFile("back.jpg")) {
            std::cerr << "Failed to load background image!" << std::endl;
        }
        backgroundSprite.setTexture(backgroundTexture);
        backgroundSprite.setScale(
            windowSize.x / backgroundSprite.getLocalBounds().width,
            windowSize.y / backgroundSprite.getLocalBounds().height
        );

        Button startButton(font, "Start Game", {windowSize.x / 2 - 100, windowSize.y / 2 - 60});
        Button exitButton(font, "Exit", {windowSize.x / 2 - 100, windowSize.y / 2 + 20});
        buttons.push_back(startButton);
        buttons.push_back(exitButton);
    }

    void handleEvents(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            for (auto& button : buttons) {
                button.handleClick(mousePos);
            }
        }

        for (const auto& button : buttons) {
            if (button.wasClicked() && button.getText() == "Start Game") {
                startClicked = true;
            } else if (button.wasClicked() && button.getText() == "Exit") {
                exitClicked = true;
            }
        }
    }

    void render(sf::RenderWindow& window) {
        window.draw(backgroundSprite);  // Draw the background image
        for (auto& button : buttons) {
            button.render(window);
        }
    }

    bool isStartClicked() {
        return startClicked;
    }

    bool isExitClicked() {
        return exitClicked;
    }
};

// Intermediate Class: DynamicObject
class DynamicObject : public GameObject {
public:
    sf::Vector2f velocity;
    virtual void move(float deltaTime) = 0;
};

// Intermediate Class: StaticObject
class StaticObject : public GameObject {
public:
    virtual void display() = 0;
};

// Player Class
class Player : public StaticObject {
private:
    string name;
    int score;
    int health;
    sf::RectangleShape shape;
public:
    Player(string playerName, sf::Vector2f pos) : name(playerName), score(0), health(100) {
        position = pos;
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(position.x, position.y);
    }

    void setName(string playerName) { name = playerName; }
    void increaseScore(int amount) { score += amount; }
    void decreaseHealth(int amount) { health -= amount; }
    bool isAlive() { return health > 0; }
    int getHealth() {
        return health;
    }
    int getScore() {
        return score;
    }

    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }

    void display() override {
        cout << "Player: " << name << " Score: " << score << " Health: " << health << endl;
    }
};

// Food Class
class Food : public DynamicObject {
public:
    enum FoodType { Healthy, Unhealthy };
    FoodType type;
    sf::CircleShape shape;

    Food(FoodType foodType, sf::Vector2f pos) : type(foodType) {
        position = pos;
        shape.setRadius(20);
        shape.setFillColor(type == Healthy ? sf::Color::Green : sf::Color::Red);
        shape.setPosition(position.x, position.y);
    }

    FoodType getType() { return type; }
    sf::Vector2f getPosition() { return position; }

    void move(float deltaTime) override {
        position.y += velocity.y * deltaTime;
        shape.setPosition(position.x, position.y);
    }

    void update(float deltaTime) override {
        move(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }
};

// Slicer Class
class Slicer : public DynamicObject {
private:
    float speed;
    sf::RectangleShape shape;
public:
    Slicer(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        shape.setSize(sf::Vector2f(30, 10));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position.x, position.y);
    }

    void moveLeft() { position.x -= 50; }
    void moveRight() { position.x += 50; }
     void moveUp() { position.y -= 50;}
    void moveDown() { position.y += 50;}
    sf::Vector2f getPosition() { return position; }

    void move(float deltaTime) override {
        // Movement handled in input
    }

    void update(float deltaTime) override {
        shape.setPosition(position.x, position.y);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }
};

// PowerUp Class
class PowerUp : public DynamicObject {
public:
    enum PowerUpType { DoubleScore, Invincibility };
    PowerUpType type;
    sf::CircleShape shape;

    PowerUp(PowerUpType powerUpType, sf::Vector2f pos) : type(powerUpType) {
        position = pos;
        shape.setRadius(15);
        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(position.x, position.y);
    }

    PowerUpType getType() { return type; }
    sf::Vector2f getPosition() { return position; }

    void move(float deltaTime) override {
        position.y += velocity.y * deltaTime;
        shape.setPosition(position.x, position.y);
    }

    void update(float deltaTime) override {
        move(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }
};

// Obstacle Class
class Obstacle : public DynamicObject {
private:
    float speed;
    sf::RectangleShape shape;
public:
    Obstacle(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        shape.setSize(sf::Vector2f(50, 50));
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position.x, position.y);
    }

    void move(float deltaTime) override {
        position.y += speed * deltaTime;
        shape.setPosition(position.x, position.y);
    }

    void update(float deltaTime) override {
        move(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(shape);
    }
};

// LevelManager Class
class LevelManager : public StaticObject {
private:
    int currentLevel;
    vector<Food> foods;
    vector<PowerUp> powerUps;
    vector<Obstacle> obstacles;
public:
    LevelManager() : currentLevel(1) {}

    void loadLevel(int level) { currentLevel = level; }
    void spawnFood(Food::FoodType type, sf::Vector2f pos) {
        foods.emplace_back(type, pos);
        foods.back().velocity.y = 100.0f; // Example speed
    }

    void spawnPowerUp(PowerUp::PowerUpType type, sf::Vector2f pos) {
        powerUps.emplace_back(type, pos);
        powerUps.back().velocity.y = 100.0f; // Example speed
    }

    void spawnObstacle(sf::Vector2f pos, float speed) {
        obstacles.emplace_back(pos, speed);
        obstacles.back().velocity.y = speed;
    }

    void update(float deltaTime) override {
        for (auto& food : foods) food.update(deltaTime);
        for (auto& powerUp : powerUps) powerUp.update(deltaTime);
        for (auto& obstacle : obstacles) obstacle.update(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        for (auto& food : foods) food.render(window);
        for (auto& powerUp : powerUps) powerUp.render(window);
        for (auto& obstacle : obstacles) obstacle.render(window);
    }

    void display() override {
        cout << "Current Level: " << currentLevel << endl;
    }
};

// UIManager Class
class UIManager : public StaticObject {
private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text healthText;
    sf::Text levelText;
public:
    UIManager() {
        if (!font.loadFromFile("font.ttf")) {
            cerr << "Failed to load font!" << endl;
        }
        scoreText.setFont(font);
        scoreText.setCharacterSize(20);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(10, 10);

        healthText.setFont(font);
        healthText.setCharacterSize(20);
        healthText.setFillColor(sf::Color::White);
        healthText.setPosition(10, 40);

        levelText.setFont(font);
        levelText.setCharacterSize(20);
        levelText.setFillColor(sf::Color::White);
        levelText.setPosition(10, 70);
    }

    void displayScore(int score) {
        scoreText.setString("Score: " + to_string(score));
    }

    void displayHealth(int health) {
        healthText.setString("Health: " + to_string(health));
    }

    void displayLevel(int level) {
        levelText.setString("Level: " + to_string(level));
    }

    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {
        window.draw(scoreText);
        window.draw(healthText);
        window.draw(levelText);
    }

    void display() override {}
};

// AudioManager Class
class AudioManager : public StaticObject {
private:
    sf::Music backgroundMusic;
public:
    AudioManager() {
        if (!backgroundMusic.openFromFile("back.ogg")) {
            cerr << "Failed to load background music!" << endl;
        }
        backgroundMusic.setLoop(true);
    }

    void playBackgroundMusic() {
        backgroundMusic.play();
    }

    void stopBackgroundMusic() {
        backgroundMusic.stop();
    }

    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {}

    void display() override {}
};

enum class GameState {
    StartScreen,
    Playing,
    GameOver
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Food Slasher");
    sf::Clock clock;
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        cerr << "Failed to load font!" << endl;
        return -1;
    }

    Player player("Arshita", {100, 500});
    Slicer slicer({300, 300}, 350.0f);
    LevelManager levelManager;
    UIManager uiManager;
    AudioManager audioManager;
    StartScreen startScreen(font, {800, 600});

    GameState gameState = GameState::StartScreen;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (gameState == GameState::StartScreen) {
                startScreen.handleEvents(event, window);
                if (startScreen.isStartClicked()) {
                    gameState = GameState::Playing;
                    sf::Texture background;
                    if (!background.loadFromFile("back.jpg")) {
                        std::cerr << "Failed to load background image!" << std::endl;
                    }
                } else if (startScreen.isExitClicked()) {
                    window.close();
                }
            }
        }

        if (gameState == GameState::Playing) {
            sf::Texture background;
            if (!background.loadFromFile("back.jpg")) {
                std::cerr << "Failed to load background image!" << std::endl;
            }

            // Player controls
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

            // Update
            slicer.update(deltaTime);
            levelManager.update(deltaTime);

            // Render
            window.clear();
            player.render(window);
            slicer.render(window);
            levelManager.render(window);
            uiManager.displayScore(player.getScore());
            uiManager.displayHealth(player.getHealth());
            uiManager.displayLevel(1);
            uiManager.render(window);
            window.display();
        } else if (gameState == GameState::StartScreen) {
            window.clear();
            startScreen.render(window);
            window.display();
        }
    }

    return 0;
}