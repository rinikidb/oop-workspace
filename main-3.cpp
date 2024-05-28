#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.initGame(3, 3, 10, 10);
    
    std::vector<GameEntity*> entities = game.get_entities();
    std::cout << "Initial game state:\n";
    for (auto entity : entities) {
        std::cout << "Entity type: " << entity->get_type() << " at position: (" 
                  << std::get<0>(entity->getPos()) << ", " << std::get<1>(entity->getPos()) << ")\n";
    }

    game.gameLoop(10, 1.5);
    
    return 0;
}
