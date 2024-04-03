// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
protected:
    std::string name;
    int health;
    int damage;

public:
    Player(std::string name, int health, int damage);
    virtual ~Player() {}

    std::string getName() const;
    int getHealth() const;
    int getDamage() const;

    void setHealth(int newHealth);

    virtual void attack(Player* opponent, int damage);
    virtual void takeDamage(int damage);
};

#endif // PLAYER_H