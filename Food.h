#ifndef FOOD_H
#define FOOD_H

#include "DynamicObject.h"

class Food : public DynamicObject {
public:
    enum FoodType { Healthy, Unhealthy };
    enum SpecificFood { Burger, Pizza, Fries, ColdDrinks, Donut, Strawberry, Broccoli, Orange, Banana, Watermelon };
    FoodType type;
    SpecificFood specificFood;
    sf::Sprite sprite; 
    static sf::Texture burgerTexture, pizzaTexture, friesTexture, coldDrinksTexture, donutTexture;
    static sf::Texture strawberryTexture, broccoliTexture, orangeTexture, bananaTexture, watermelonTexture;
    static std::vector<Food*> activeFoods;

    Food(FoodType foodType, SpecificFood specFood, sf::Vector2f pos);
    ~Food();
    void updateAll(float deltaTime);
    void renderAll(sf::RenderWindow& window);
    void spawnFood(FoodType foodType, SpecificFood specFood, sf::Vector2f pos); 
    void setTexture();
    void resizeSprite();
    void move(float deltaTime) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    sf::FloatRect getBounds() const;
};

#endif // FOOD_H
