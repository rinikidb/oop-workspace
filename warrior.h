// warrior.h
#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"
#include <string>

class Warrior : public Player {
private:
    std::string weapon;

public:
    Warrior(std::string name, int health, int damage, std::string weapon);

    std::string getWeapon() const;
    void setWeapon(std::string newWeapon);

    void swingWeapon(Player* opponent);
};

#endif // WARRIOR_H