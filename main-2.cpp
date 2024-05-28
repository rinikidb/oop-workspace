#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    Ship ship(5, 5);
    Mine mine(7, 7);

    std::cout << "Initial ship position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";
    ship.move(1, 0);
    std::cout << "Moved ship position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";

    Explosion explosion = mine.explode();
    std::cout << "Mine exploded at position: (" << std::get<0>(explosion.getPos()) << ", " << std::get<1>(explosion.getPos()) << ")\n";

    explosion.apply(ship);
    std::cout << "Ship position after explosion: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";
    std::cout << "Ship type after explosion: " << ship.getType() << "\n";

    return 0;
}
