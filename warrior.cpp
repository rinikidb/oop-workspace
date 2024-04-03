// warrior.cpp
#include "warrior.h" 
#include <iostream>

Warrior::Warrior(std::string name, int health, int damage, std::string weapon) : Player(name, health, damage), weapon(weapon) {}

std::string Warrior::getWeapon() const {
    return weapon;
}

void Warrior::setWeapon(std::string newWeapon) {
    weapon = newWeapon;
}

void Warrior::swingWeapon(Player* opponent) {
    std::cout << name << " swings their " << weapon << " at " << opponent->getName() << "!\n";
    opponent->takeDamage(damage); // Assuming the warrior deals fixed damage regardless of weapon
}