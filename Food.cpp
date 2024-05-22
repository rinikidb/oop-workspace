#include <iostream> 
#include "Food.h" 

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

Food::Food(FoodType foodType, SpecificFood specFood, sf::Vector2f pos) : type(foodType), specificFood(specFood) {
        position = pos;
        sprite.setPosition(position.x, position.y);
        setTexture();
        resizeSprite();
    }

    // Destructor to remove the food object from activeFoods vector
Food::~Food() {
        // Find and remove this food object from activeFoods
        auto it = std::find(activeFoods.begin(), activeFoods.end(), this);
        if (it != activeFoods.end()) {
            activeFoods.erase(it);
        }
    }

// Static method to update all active food objects
void Food::updateAll(float deltaTime) {
        for (auto& food : activeFoods) {
            food->update(deltaTime);
        }
    }

    // Static method to render all active food objects
void Food::renderAll(sf::RenderWindow& window) {
        for (auto& food : activeFoods) {
            food->render(window);
        }
    }

    // Static method to spawn a new food object if the number of active food objects is less than 5
void Food::spawnFood(FoodType foodType, SpecificFood specFood, sf::Vector2f pos) {
        if (activeFoods.size() < 7) {
            Food* newFood = new Food(foodType, specFood, pos);
            activeFoods.push_back(newFood);
        }
    }


    // Set texture based on specific food type
void Food::setTexture() {
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

void Food::resizeSprite() {
        float targetWidth = 100.0f;
        float targetHeight = 100.0f;

        sf::Vector2u textureSize = sprite.getTexture()->getSize();
        float scaleX = targetWidth / textureSize.x;
        float scaleY = targetHeight / textureSize.y;

        sprite.setScale(scaleX, scaleY);
    }

void Food::move(float deltaTime){
        position.y += velocity.y * deltaTime;
        sprite.setPosition(position.x, position.y);
    }

void Food::update(float deltaTime){
        move(deltaTime);
    }

void Food::render(sf::RenderWindow& window){
        window.draw(sprite);
    }

sf::FloatRect Food::getBounds() const { 
        return sprite.getGlobalBounds();   
}