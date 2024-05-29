#include <iostream>
#include <vector>
#include "Game.h"
#include <tuple>
 
using namespace std;

int main(){

    Game game;

    game.initGame(3,3,10,10);

    vector<GameEntity*> entities = game.get_entities();
    
    for(auto entity:entities){
        cout << "Entity type: " << entity->getType() << endl;
        cout << "Entity position: (" << get<0>(entity->getPos()) << "," << get<1>(entity->getPos()) << ")" << endl;
    }
    

    game.gameLoop(5,1.5);




    return 0;
}