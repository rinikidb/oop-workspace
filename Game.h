#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector> 
#include <tuple>
#include <algorithm>
#include "GameEntity.h"
#include "Utils.h"
#include "Ship.h"
#include "Mine.h"

using namespace std;

class Game{
    private:
        vector<GameEntity*> entities;
    public:
        vector<GameEntity*> get_entities()const{
            return entities;
        }

        void set_entities(vector<GameEntity*> entities){
            this->entities = entities;
        }

        vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight){
            for (int i = 0; i < numShips; i++){
                tuple<int,int> pos = Utils::generateRandomPos(gridWidth,gridHeight);
                Ship* ship = new Ship(get<0>(pos), get<1>(pos));
                entities.push_back(ship);      
            }

            for (int i = 0; i < numShips; i++){
                tuple<int,int> pos = Utils::generateRandomPos(gridWidth,gridHeight);
                Mine* mine = new Mine(get<0>(pos), get<1>(pos));
                entities.push_back(mine);      
            }

            return entities;
        }

        void gameLoop(int maxIterations, double mineDistanceThreshold){
            for(int i = 0; i < maxIterations; i++){
                for(auto a:entities){
                    if (a->get_type() == 'S'){
                        Ship* ship = static_cast<Ship*>(a);
                        ship->move(1, 0); 
                    }
                }

                for(auto entity:entities){
                    if (entity->get_type() == 'S'){
                        Ship* ship = static_cast<Ship*>(entity);
                        for(auto entity:entities){
                            if(entity->get_type() == 'M'){
                                Mine* mine = static_cast<Mine*>(entity);
                                double dist = Utils::calculateDistance(mine->getPos(), ship->getPos());
                                if(dist <= mineDistanceThreshold){
                                    Explosion explosion = mine->explode();
                                    explosion.apply(*ship);
                                }
                            }
                        }
                    }
                }

                
                if (std::none_of(entities.begin(), entities.end(), [](GameEntity* entity) { return entity->get_type() == 'S'; })) {
                    std::cout << "All ships are destroyed. Game over.\n";
                    return;
                }
                        
                
            }
            
        }

};


#endif