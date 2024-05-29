#ifndef GAME_H
#define GAME_H

#include <iostream>
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
        void set_entities(vector<GameEntity*> entities){
            this->entities = entities; 
        }
        vector<GameEntity*> get_entities(){
            return entities;
        }
        vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight){
            for(int i = 0; i < numShips; i++){
                tuple<int,int> pos = Utils::generateRandomPos(gridWidth,gridHeight);
                Ship* ship = new Ship(get<0>(pos),get<1>(pos));
                entities.push_back(ship); 
            }

            for(int i = 0; i < numMines; i++){
                tuple<int,int> pos = Utils::generateRandomPos(gridWidth,gridHeight);
                Mine* mine = new Mine(get<0>(pos),get<1>(pos));
                entities.push_back(mine); 
            }

            return entities;
        }

        void gameLoop(int maxIterations, double mineDistanceThreshold){
            for(int i = 0; i < maxIterations; i++){
                for(auto entity:entities){
                    if(entity->getType() == 'S'){
                        Ship* ship = static_cast<Ship*>(entity); 
                        ship->move(1,0); 
                    }
                }

                for(auto entity:entities){
                    if(entity->getType() == 'S'){
                        Ship* ship = static_cast<Ship*>(entity);
                        tuple<int,int> shipPos = ship->getPos();
                        for(auto entity:entities){
                            if(entity->getType() == 'M'){
                                Mine* mine = static_cast<Mine*>(entity);
                                tuple<int,int> minePos = mine->getPos();
                                double dist = Utils::calculateDistance(shipPos,minePos);
                                if (dist <= mineDistanceThreshold){
                                    mine->explode();
                                }
                            }
                        }
                    }
                }

                if(none_of(entities.begin(),entities.end(), [](GameEntity* entity) {return entity->getType() == 'S';})){
                    return; 
                }
            }
        }


};

#endif