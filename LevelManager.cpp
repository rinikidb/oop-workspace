#include <iostream> 
#include "LevelManager.h" 
#include <random>

using namespace std;

void LevelManager::updateSpawnInterval() {  
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

LevelManager::LevelManager() : spawnTimer(0.0f), spawnInterval(2.0f) { 
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
    void LevelManager::loadLevel(int level) {
        currentLevel = level;
        updateSpawnInterval();
        // Adjust speed based on the selected level
        
    }

    std::vector<Food>& LevelManager::getFoods() { return foods; } 

    // Function to spawn food randomly
    void LevelManager::spawnFoodRandomly() {
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

    std::vector<Obstacle>& LevelManager::getObstacles() { return obstacles; }           

    void LevelManager::spawnObstacleRandomly() {  
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xPosDist(0, 800);  // Random x position within window width
        float xPos2 = xPosDist(gen);
        sf::Vector2f spawnPos2(xPos2, 0);  // Start spawning from top of window
        Obstacle newObstacle(spawnPos2, 100.0f); 
        obstacles.push_back(newObstacle); 
    }

    std::vector<PowerUp>& LevelManager::getPowerUps() { return powerUps; }

    void LevelManager::spawnPowerUpRandomly() { 
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xPosDist(0, 800);  // Random x position within window width
        float xPos3 = xPosDist(gen);
        sf::Vector2f spawnPos3(xPos3, 0);  // Start spawning from top of window
        PowerUp newPowerUp(spawnPos3, 100.f);  
        powerUps.push_back(newPowerUp);
    }

    void LevelManager::update(float deltaTime){

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

    void LevelManager::render(sf::RenderWindow& window) {
        for (auto& food : foods) food.render(window);
        for (auto& powerUp : powerUps) powerUp.render(window);
        for (auto& obstacle : obstacles) obstacle.render(window);
    }

    void LevelManager::display()  {
        cout << "Current Level: " << currentLevel << endl;
    }