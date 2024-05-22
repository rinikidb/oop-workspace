#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Food.h"
#include "PowerUp.h"  
#include "Obstacle.h"
#include "StaticObject.h"
using namespace std;

class LevelManager : public StaticObject {
private:
    int currentLevel;
    vector<Food> foods; 
    vector<PowerUp> powerUps;
    vector<Obstacle> obstacles;
    float spawnTimer;          // Timer for food spawning
    float spawnInterval;       // Interval between spawns 

public:
    void updateSpawnInterval();
    LevelManager();
    void loadLevel(int level);
    void spawnFoodRandomly();
    void spawnObstacleRandomly();
    void spawnPowerUpRandomly(); 
    std::vector<Food>& getFoods();
    std::vector<Obstacle>& getObstacles();
    std::vector<PowerUp>& getPowerUps();
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    void display() override;
};

#endif // LEVELMANAGER_H
