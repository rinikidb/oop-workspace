// player.cpp
#include "player.h"
#include <iostream>

Player::Player(std::string name, int health, int damage) : name(name), health(health), damage(damage) {}

std::string Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getDamage() const {
    return damage;
}

void Player::setHealth(int newHealth) {
    health = newHealth;
}

void Player::attack(Player* opponent, int damage) {
    opponent->takeDamage(damage);
}

void Player::takeDamage(int damage) {
    health -= damage;
    std::cout << name << " takes " << damage << " damage. Remaining health: " << health << "\n";
}