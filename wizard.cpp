// wizard.cpp
#include "wizard.h" 
#include <iostream>

Wizard::Wizard(std::string name, int health, int damage, int mana) : Player(name, health, damage), mana(mana) {}

int Wizard::getMana() const {
    return mana;
}

void Wizard::setMana(int newMana) {
    mana = newMana;
}

void Wizard::castSpell(Player* opponent) {
    if (mana > 0) {
        std::cout << name << " casts a spell on " << opponent->getName() << " for " << mana << " damage.\n";
        opponent->takeDamage(mana);
        mana -= mana; // assuming all mana is consumed after each spell
    } else {
        std::cout << "Not enough mana to cast a spell!\n";
    }
}