#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <random>

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
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position.x, position.y);

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(position.x + 20, position.y + 10);  // Adjust text position for centering
    }

    void centerText() {
        // Calculate the center of the button
        sf::Vector2f buttonCenter = position + sf::Vector2f(shape.getSize().x / 2, shape.getSize().y / 2);

        // Calculate the position to center the text within the button
        sf::Vector2f textPosition;
        textPosition.x = buttonCenter.x - text.getLocalBounds().width / 2;
        textPosition.y = buttonCenter.y - text.getLocalBounds().height / 2;

        // Set the position of the text
        text.setPosition(textPosition);
    }  

    void handleClick(sf::Vector2i mousePos) {
        if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
            isClicked = true;
        }
    }

    bool wasClicked() const {
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
    sf::Vector2f windowSize;
    std::vector<Button> buttons;
    bool startClicked;
    bool exitClicked;
    int selectedLevel;

public:
    StartScreen(sf::Font& font, sf::Vector2f windowSize, const std::string& backgroundFilename)
        : startClicked(false), exitClicked(false), selectedLevel(1){

        this->windowSize = windowSize;

        // Load the background texture
        if (!backgroundTexture.loadFromFile(backgroundFilename)) {
            cerr << "Failed to load background image!" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);

        // Scale the background to fit the window
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x;
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);

        // Create buttons
        Button startButton(font, "Start Game", { windowSize.x / 2 - 100, windowSize.y / 2 - 60 });
        startButton.centerText();
        Button exitButton(font, "Exit", { windowSize.x / 2 - 100, windowSize.y / 2 + 20 });
        exitButton.centerText();
        buttons.push_back(startButton);
        buttons.push_back(exitButton);
    }

    sf::Vector2f getWindowSize(){
            return windowSize; 
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
            }
            else if (button.wasClicked() && button.getText() == "Exit") {
                exitClicked = true;
            }
        }
    }

    void render(sf::RenderWindow& window) {
        // Draw the background
        window.draw(backgroundSprite);

        // Draw the buttons
        for (auto& button : buttons) {
            button.render(window);
        }
    }

    bool isStartClicked() const {
        return startClicked;
    }

    bool isExitClicked() const {
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
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
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
    string getName() const { return name; }
    void increaseScore(int amount) { score += amount; }
    void decreaseHealth(int amount) { health -= amount; }
    bool isAlive() { return health > 0; }
    int getHealth() { return health; }
    void setHealth(int health){
        this->health = health;  
    }
    int getScore() { return score; }

    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {
        //window.draw(shape);
    }

    void display() override {
        cout << "Player: " << name << " Score: " << score << " Health: " << health << endl;
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }


    void getPlayerName(sf::RenderWindow& window, sf::Font& font, sf::Vector2f windowSize) {

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
};



// Food Class
class Food : public DynamicObject {
public:
    enum FoodType { Healthy, Unhealthy };
    enum SpecificFood { Burger, Pizza, Fries, ColdDrinks, Donut, Strawberry, Broccoli, Orange, Banana, Watermelon };
    FoodType type;
    SpecificFood specificFood;
    sf::Sprite sprite;  // Change to sf::Sprite
    static sf::Texture burgerTexture, pizzaTexture, friesTexture, coldDrinksTexture, donutTexture;
    static sf::Texture strawberryTexture, broccoliTexture, orangeTexture, bananaTexture, watermelonTexture;
    // Add a static vector to keep track of active food objects
    static std::vector<Food*> activeFoods;

    Food(FoodType foodType, SpecificFood specFood, sf::Vector2f pos) : type(foodType), specificFood(specFood) {
        position = pos;
        sprite.setPosition(position.x, position.y);
        setTexture();
        resizeSprite();
    }

    // Destructor to remove the food object from activeFoods vector
    ~Food() {
        // Find and remove this food object from activeFoods
        auto it = std::find(activeFoods.begin(), activeFoods.end(), this);
        if (it != activeFoods.end()) {
            activeFoods.erase(it);
        }
    }

    // Static method to update all active food objects
    static void updateAll(float deltaTime) {
        for (auto& food : activeFoods) {
            food->update(deltaTime);
        }
    }

    // Static method to render all active food objects
    static void renderAll(sf::RenderWindow& window) {
        for (auto& food : activeFoods) {
            food->render(window);
        }
    }

    // Static method to spawn a new food object if the number of active food objects is less than 5
    static void spawnFood(FoodType foodType, SpecificFood specFood, sf::Vector2f pos) {
        if (activeFoods.size() < 7) {
            Food* newFood = new Food(foodType, specFood, pos);
            activeFoods.push_back(newFood);
        }
    }


    // Set texture based on specific food type
    void setTexture() {
        switch (specificFood) {
        case Burger:
            sprite.setTexture(burgerTexture);
            break;
        case Pizza:
            sprite.setTexture(pizzaTexture);
            break;
        case Fries:
            sprite.setTexture(friesTexture);
            break;
        case ColdDrinks:
            sprite.setTexture(coldDrinksTexture);
            break;
        case Donut:
            sprite.setTexture(donutTexture);
            break;
        case Strawberry:
            sprite.setTexture(strawberryTexture);
            break;
        case Broccoli:
            sprite.setTexture(broccoliTexture);
            break;
        case Orange:
            sprite.setTexture(orangeTexture);
            break;
        case Banana:
            sprite.setTexture(bananaTexture);
            break;
        case Watermelon:
            sprite.setTexture(watermelonTexture);
            break;
        }
    }

    void resizeSprite() {
        float targetWidth = 100.0f;
        float targetHeight = 100.0f;

        sf::Vector2u textureSize = sprite.getTexture()->getSize();
        float scaleX = targetWidth / textureSize.x;
        float scaleY = targetHeight / textureSize.y;

        sprite.setScale(scaleX, scaleY);
    }

    void move(float deltaTime) override {
        position.y += velocity.y * deltaTime;
        sprite.setPosition(position.x, position.y);
    }

    void update(float deltaTime) override {
        move(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(sprite);
    }

    sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }
};

// Initialize static members
std::vector<Food*> Food::activeFoods; 
sf::Texture Food::burgerTexture;
sf::Texture Food::pizzaTexture;
sf::Texture Food::friesTexture; 
sf::Texture Food::coldDrinksTexture;
sf::Texture Food::donutTexture;
sf::Texture Food::strawberryTexture;
sf::Texture Food::broccoliTexture;
sf::Texture Food::orangeTexture;
sf::Texture Food::bananaTexture;
sf::Texture Food::watermelonTexture;



// Slicer Class
class Slicer : public DynamicObject {
private:
    float speed;
    //sf::RectangleShape shape
    sf :: CircleShape shape;
public:
    /*Slicer(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        shape.setSize(sf::Vector2f(20, 20));
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position.x, position.y);
    } */
    Slicer(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        shape.setRadius(5); // Set radius for the circle slicer
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(position.x - shape.getRadius(), position.y - shape.getRadius());
    }

    /*
    void moveLeft() { position.x -= 20; }
    void moveRight() { position.x += 20; }
    void moveUp() { position.y -= 20; }
    void moveDown() { position.y += 20; }
    */
    
    void moveTowards(sf::Vector2f target) {
        sf::Vector2f direction = target - position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (distance > 0) {
            direction /= distance;
            position += direction * speed;
        }
    }

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

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    }

    void updateShapePosition(sf::Vector2i mousePos) {
        position = static_cast<sf::Vector2f>(mousePos); // Set the slicer's position to match mouse position
        shape.setPosition(position.x - shape.getRadius(), position.y - shape.getRadius()); // Adjust position of the circle shape
    }
};

// PowerUp Class
class PowerUp : public DynamicObject {
private:
    float speed;
    static sf::Texture powerUpTexture;
    sf::Sprite powerUpSprite; 
public:
    PowerUp(sf::Vector2f pos, float spd) : speed(spd){
    position = pos;
    powerUpSprite.setPosition(position.x,position.y);
    resizePowerUpSprite();

    // Load the background texture
            if (!powerUpTexture.loadFromFile("powerUp.jpeg")) {
                cerr << "Failed to load background image!" << endl;
            }
            powerUpSprite.setTexture(powerUpTexture); 
        }

        void move(float deltaTime) override {
            position.y += speed * deltaTime;
            powerUpSprite.setPosition(position.x, position.y);
        }

        void update(float deltaTime) override {
            move(deltaTime);
        }

        void render(sf::RenderWindow& window) override {
            window.draw(powerUpSprite);
        }

        void resizePowerUpSprite() {
            float targetWidth = 100.0f;
            float targetHeight = 100.0f; 

            sf::Vector2u textureSize = powerUpTexture.getSize();  
            float scaleX = targetWidth / textureSize.x;
            float scaleY = targetHeight / textureSize.y;

            powerUpSprite.setScale(scaleX, scaleY);
        }


        sf::FloatRect getBounds() const {
            return powerUpSprite.getGlobalBounds();
        }
};
sf::Texture PowerUp :: powerUpTexture;

// Obstacle Class
class Obstacle : public DynamicObject {
private:
    float speed;
    static sf::Texture obstacleTexture;
    sf::Sprite obstacleSprite; 
public:
    Obstacle(sf::Vector2f pos, float spd) : speed(spd) {
        position = pos;
        obstacleSprite.setPosition(position.x, position.y);
        resizeObstacleSprite(); 

        // Load the background texture
        if (!obstacleTexture.loadFromFile("obstacle.jpeg")) {
            cerr << "Failed to load background image!" << endl;
        }
        obstacleSprite.setTexture(obstacleTexture); 
    }

    void move(float deltaTime) override {
        position.y += speed * deltaTime;
        obstacleSprite.setPosition(position.x, position.y);
    }

    void update(float deltaTime) override {
        move(deltaTime);
    }

    void render(sf::RenderWindow& window) override {
        window.draw(obstacleSprite);
    }

    void resizeObstacleSprite() {
        float targetWidth = 100.0f;
        float targetHeight = 100.0f; 

        sf::Vector2u textureSize = obstacleTexture.getSize();  
        float scaleX = targetWidth / textureSize.x;
        float scaleY = targetHeight / textureSize.y;

        obstacleSprite.setScale(scaleX, scaleY);
    }

    sf::FloatRect getBounds() const {
        return obstacleSprite.getGlobalBounds();
    }
};

sf::Texture Obstacle::obstacleTexture;

// UIManager Class
class UIManager : public StaticObject {
private:
    sf::Font font;
    sf::Text scoreText;
    sf::Text healthText;
    sf::Text levelText;
    sf::Text nameText;

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

        nameText.setFont(font);
        nameText.setCharacterSize(20);
        nameText.setFillColor(sf::Color::White);
        nameText.setPosition(10, 100);
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

    void displayName(const string& name) {
        nameText.setString("Player: " + name);
    }

    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {
        window.draw(scoreText);
        window.draw(healthText);
        window.draw(levelText);
        window.draw(nameText);
    }

    void display() override {}
};

// AudioManager Class
class AudioManager : public StaticObject {
public:

    // Declare and load sound effects
        sf::SoundBuffer scoreUpSoundBuffer;
        sf::SoundBuffer scoreDownSoundBuffer;
        sf::SoundBuffer backgroundMusicBuffer;
        sf::SoundBuffer gameOverMusicBuffer;

    sf::Sound scoreUpSound; 
    sf::Sound scoreDownSound;
    sf::Sound gameOverMusicSound;
    sf::Sound backgroundMusicSound; 

    AudioManager() { 

        if (!scoreUpSoundBuffer.loadFromFile("healthy_food.ogg")) {
            cerr << "Failed to load healthy food sound!" << endl;
        }
        if (!scoreDownSoundBuffer.loadFromFile("unhealthy_food.ogg")) {
            cerr << "Failed to load unhealthy food sound!" << endl;
        }
        
        if (!backgroundMusicBuffer.loadFromFile("back.ogg")) {
            cerr << "Failed to load unhealthy food sound!" << endl;
        }
        
        if (!gameOverMusicBuffer.loadFromFile("gameOver.ogg")) {
            cerr << "Failed to load unhealthy food sound!" << endl;
        }

        scoreUpSound.setBuffer(scoreUpSoundBuffer);
        scoreDownSound.setBuffer(scoreDownSoundBuffer); 
        gameOverMusicSound.setBuffer(gameOverMusicBuffer);
        backgroundMusicSound.setBuffer(backgroundMusicBuffer);

    }
                
    void update(float deltaTime) override {}

    void render(sf::RenderWindow& window) override {}

    void display() override {}
};

// LevelManager Class
class LevelManager : public StaticObject {
private:
    int currentLevel;
    vector<Food> foods;
    vector<PowerUp> powerUps;
    vector<Obstacle> obstacles;
    float spawnTimer;          // Timer for food spawning
    float spawnInterval;       // Interval between spawns
    

public:
    LevelManager() : spawnTimer(0.0f), spawnInterval(2.0f) { 
        // spawnInterval in seconds
        if (!Food::burgerTexture.loadFromFile("burger.jpeg")) {
            cerr << "Failed to load burger texture!" << endl;
        }
        if (!Food::pizzaTexture.loadFromFile("pizza.jpeg")) {
            cerr << "Failed to load pizza texture!" << endl;
        }
        if (!Food::friesTexture.loadFromFile("fries.jpeg")) {
            cerr << "Failed to load fries texture!" << endl;
        }
        if (!Food::coldDrinksTexture.loadFromFile("cold_drinks.jpeg")) {
            cerr << "Failed to load cold drinks texture!" << endl;
        }
        if (!Food::donutTexture.loadFromFile("donut.jpeg")) {
            cerr << "Failed to load donut texture!" << endl;
        }
        if (!Food::strawberryTexture.loadFromFile("strawberry.jpeg")) {
            cerr << "Failed to load strawberry texture!" << endl;
        }
        if (!Food::broccoliTexture.loadFromFile("broccoli.jpeg")) {
            cerr << "Failed to load broccoli texture!" << endl;
        }
        if (!Food::orangeTexture.loadFromFile("orange.jpeg")) {
            cerr << "Failed to load orange texture!" << endl;
        }
        if (!Food::bananaTexture.loadFromFile("banana.jpeg")) {
            cerr << "Failed to load banana texture!" << endl;
        }
        if (!Food::watermelonTexture.loadFromFile("watermelon.jpeg")) {
            cerr << "Failed to load watermelon texture!" << endl;
        }
        
        //if (!obstacleTexture.loadFromFile("obstacle.jpeg")) {
         //   cerr << "Failed to load obstacle texture!" << endl;
        //}
        
        updateSpawnInterval(); 
    }

    //void loadLevel(int level) { currentLevel = level; }
    void loadLevel(int level) {
        currentLevel = level;
        updateSpawnInterval();
        // Adjust speed based on the selected level
        
    }

    void updateSpawnInterval() { 
        // Adjust speed based on the selected level
        switch (currentLevel) {
            case 1:
                spawnInterval = 2.0f;
                break;
            case 2:
                spawnInterval = 1.5f; // Faster spawn interval for level 2
                break;
            case 3:
                spawnInterval = 1.0f; // Even faster for level 3
                break;
            default:
                spawnInterval = 2.0f;
        }
    }   

    std::vector<Food>& getFoods() { return foods; }

    // Function to spawn food randomly
    void spawnFoodRandomly() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> typeDist(0, 1);  // Randomly choose between healthy and unhealthy
        std::uniform_int_distribution<int> specificFoodDist(0, 4);  // Randomly choose specific food
        std::uniform_real_distribution<float> xPosDist(0, 800);  // Random x position within window width
        int type = typeDist(gen);
        int specificFood = specificFoodDist(gen);
        float xPos1 = xPosDist(gen);
        //float xPos2 = xPosDist(gen);
        Food::FoodType foodType = static_cast<Food::FoodType>(type);
        Food::SpecificFood specificFoodType = static_cast<Food::SpecificFood>(specificFood + (type == 0 ? 5 : 0)); // Offset by 5 for healthy foods
        sf::Vector2f spawnPos1(xPos1, 0);  // Start spawning from top of window
        //sf::Vector2f spawnPos2(xPos2, 0);  // Start spawning from top of window
        Food newFood(foodType, specificFoodType, spawnPos1);
        //Obstacle newObstacle(spawnPos2, 200.0f); 
        newFood.velocity.y = 100.0f;  // Example speed
        foods.push_back(newFood);
    }

    std::vector<Obstacle>& getObstacles() { return obstacles; }

    void spawnObstacleRandomly() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xPosDist(0, 800);  // Random x position within window width
        float xPos2 = xPosDist(gen);
        sf::Vector2f spawnPos2(xPos2, 0);  // Start spawning from top of window
        Obstacle newObstacle(spawnPos2, 100.0f); 
        obstacles.push_back(newObstacle); 
    }

    std::vector<PowerUp>& getPowerUps() { return powerUps; }

    void spawnPowerUpRandomly() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xPosDist(0, 800);  // Random x position within window width
        float xPos3 = xPosDist(gen);
        sf::Vector2f spawnPos3(xPos3, 0);  // Start spawning from top of window
        PowerUp newPowerUp(spawnPos3, 100.f);
        powerUps.push_back(newPowerUp);
    }

    void update(float deltaTime) override {

        spawnTimer += deltaTime;  // Update the spawn timer

        if (spawnTimer >= spawnInterval) {
            spawnFoodRandomly();  // Spawn food when the timer exceeds the interval
            spawnObstacleRandomly();
            spawnPowerUpRandomly();
            spawnTimer = 0.0f;    // Reset the spawn timer
        }

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


enum class GameState {
    StartScreen,
    NameInput,
    LevelSelection,
    Playing,
    GameOver
    
};

class LevelButton {
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isClicked;

public:
    LevelButton(sf::Font& font, const std::string& levelName, const sf::Vector2f& position)
        : isClicked(false) {
        shape.setSize(sf::Vector2f(200, 50)); // Adjust size as needed
        shape.setFillColor(sf::Color::Red);
        shape.setPosition(position);

        text.setFont(font);
        text.setString(levelName);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        // Center text within the button
        sf::FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        text.setPosition(position.x + shape.getSize().x / 2.0f, position.y + shape.getSize().y / 2.0f);
    }

    void handleClick(const sf::Vector2i& mousePos) {
        isClicked = shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
    }

    bool wasClicked() const {
        return isClicked;
    }

    void resetClick() {
        isClicked = false;
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
        window.draw(text);
    }
  
    std::string getText() const {
        return text.getString();  
    }
}; 

class LevelSelectionScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Vector2f windowSize;
    std::vector<Button> buttons;

public:
    LevelSelectionScreen(sf::Vector2f windowSize, const std::string& backgroundFilename) {

        this->windowSize = windowSize;

        // Load the background texture
        if (!backgroundTexture.loadFromFile(backgroundFilename)) {
            cerr << "Failed to load background image!" << endl; 
        }
        backgroundSprite.setTexture(backgroundTexture);

        // Scale the background to fit the window
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x; 
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);

    } 

    void createLevelButtons(sf::Font& font) {
        sf::Vector2f buttonPosition1(windowSize.x / 2 - 100, windowSize.y / 2 - 80); // Adjust positions as needed
        sf::Vector2f buttonPosition2(windowSize.x / 2 - 100, windowSize.y / 2 - 20); 
        sf::Vector2f buttonPosition3(windowSize.x / 2 - 100, windowSize.y / 2 + 40);

        buttons.emplace_back(font, "Level 1", buttonPosition1);
        buttons.emplace_back(font, "Level 2", buttonPosition2);
        buttons.emplace_back(font, "Level 3", buttonPosition3); 
    }
    
    int handleLevelSelection(sf::RenderWindow& window) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (auto& button : buttons) {
                    button.handleClick(mousePos);
                    if (button.wasClicked()) {
                        if (button.getText() == "Level 1") {
                            return 1;
                        } else if (button.getText() == "Level 2") {
                            return 2;
                        } else if (button.getText() == "Level 3") {
                            return 3;
                        }
                    }
                }
            }
    
        } 
        return 0; // No level selected
    }

    void render(sf::RenderWindow& window) {
        // Draw the background
        window.draw(backgroundSprite);

        // Draw the buttons
        for (auto& button : buttons) {
            button.render(window); 
        }
    }
};

// Game Over Screen Class
class GameOverScreen {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::Text scoreText;
    Button okButton;

public:
    GameOverScreen(sf::Font& font, sf::Vector2f windowSize, int score, const std::string& backgroundFilename)
        : okButton(font, "OK", { windowSize.x / 2 - 100, windowSize.y / 2 + 20 }) {
        okButton.centerText();
        scoreText.setFont(font);
        scoreText.setCharacterSize(24);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition(windowSize.x / 2 - 100, windowSize.y / 2 - 50);
        scoreText.setString("Score: " + std::to_string(score));

        // Load the background texture
        if (!backgroundTexture.loadFromFile(backgroundFilename)) {
            cerr << "Failed to load background image!" << endl;
        }
        backgroundSprite.setTexture(backgroundTexture);

        // Scale the background to fit the window
        sf::Vector2u textureSize = backgroundTexture.getSize();
        sf::Vector2f scaleFactors;
        scaleFactors.x = windowSize.x / textureSize.x;
        scaleFactors.y = windowSize.y / textureSize.y;
        backgroundSprite.setScale(scaleFactors);
        
    }

    /*
    void handleEvents(sf::Event event, sf::RenderWindow& window) {
        okButton.handleClick(sf::Mouse::getPosition(window));
    }
    */

    void handleEvents(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            okButton.handleClick(sf::Mouse::getPosition(window));
        }
    }

    bool isOKClicked() const {
        return okButton.wasClicked();
    }

    void render(sf::RenderWindow& window) {
        window.draw(backgroundSprite);
        window.draw(scoreText);
        okButton.render(window);
        
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Food Slasher!");
    window.setFramerateLimit(60);
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        cerr << "Failed to load font!" << endl;
        return -1;
    }

    StartScreen startScreen(font, { 800, 600 }, "back1.jpg");
    GameState gameState = GameState::StartScreen; 
    int selectedLevel = 0; 
    Player player("", sf::Vector2f(375, 500));  // Initialize with an empty name

    // Declare GameOverScreen object
    //GameOverScreen gameOverScreen(font, { 800, 600 }, player.getScore(), "back1.jpg");

    //LevelSelectionScreen levelSelectionScreen;

    //std::string selectedLevel;

    LevelManager levelManager; 
    AudioManager audioManager;
    UIManager uiManager;
    Slicer slicer({ 400, 550 }, 1000.0f);
    LevelSelectionScreen levelSelectionScreen({800,600}, "back1.jpg");
    levelSelectionScreen.createLevelButtons(font);

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
            audioManager.backgroundMusicSound.play();  
            StartScreen startScreen(font, { 800, 600 }, "back1.jpg");
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
            player.getPlayerName(window, font, startScreen.getWindowSize());
            audioManager.backgroundMusicSound.play(); 
            uiManager.displayName(player.getName());
            gameState = GameState::Playing;
            //gameState = GameState::LevelSelection;// Transition to LevelSelection state
        
        /*
        } else if (gameState == GameState::LevelSelection) {
            // Handle level selection 
            selectedLevel = levelSelectionScreen.handleLevelSelection(window);
            levelSelectionScreen.render(window);
            //levelSelectionScreen.render(window); 
            if (selectedLevel > 0) {
                // Load the selected level 
                levelManager.loadLevel(selectedLevel);
                levelManager.updateSpawnInterval();
                gameState = GameState::Playing;
            }
        */ 
    
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
            uiManager.displayLevel(1);  // Assuming level 1 for now; update as needed

            levelManager.render(window);
            slicer.render(window);
            player.render(window);

            // Check if health is zero and transition to Game Over state
            if (!player.isAlive()) {
                    gameState = GameState::GameOver;
                    /*
                    audioManager.backgroundMusicSound.stop();

                    audioManager.gameOverMusicSound.play();
                    audioManager.gameOverMusicSound.stop();
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

