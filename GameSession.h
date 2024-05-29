#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <iostream>
#include <vector>
#include "GridUnit.h"
#include "Helper.h"
#include "Avatar.h"
#include "Obstacle.h"
#include <algorithm> 

using namespace std;

class GameSession{
    private:
        std::vector<GridUnit*> grid;
        int gridWidth; 
    public: 
        std::vector<GridUnit*>& getGrid(){
            return grid;
        }
        void initGameSession(int numAvatars, int numObstacles, int gridWidth, int gridHeight){
            for(int i = 0; i < numAvatars; i++){
                tuple<int,int> pos = Helper::generateRandomCoordinates(gridWidth,gridHeight);
                Avatar* avatar = new Avatar(get<0>(pos),get<1>(pos));
                grid.push_back(avatar);
            }

            for(int i = 0; i < numObstacles; i++){
                tuple<int,int> pos = Helper::generateRandomCoordinates(gridWidth,gridHeight);
                Obstacle* obstacle = new Obstacle(get<0>(pos),get<1>(pos));
                grid.push_back(obstacle);
            }
            this->gridWidth = gridWidth;
        }
        void gameCycle(int maxCycles, double obstacleActivationDistance){
            for(int i = 0; i < maxCycles; i++){
                for(auto obj:grid){
                    if(obj->getEntity() == 'A'){
                        Avatar* avatar = static_cast<Avatar*>(obj);
                        avatar->shift(1,0);
                    }
                }

                for(auto obj:grid){
                    if(obj->getEntity() == 'A'){
                        Avatar* avatar = static_cast<Avatar*>(obj);
                        tuple<int,int> pos1 = avatar->getCoordinates();
                        for(auto obj:grid){
                            if(obj->getEntity() == 'O'){
                                Obstacle* obstacle = static_cast<Obstacle*>(obj);
                                tuple<int,int> pos2 = obstacle->getCoordinates();
                                
                                double dist = Helper::calculateDistance(pos1,pos2);

                                if(dist <= obstacleActivationDistance){
                                    obstacle->apply(*avatar); 
                                    if(get<0>(avatar->getCoordinates()) > gridWidth){
                                    cout << "Avatar has won the game!" << endl;
                                    break;
                        }
                                }



                            }
                        }
                        
                    }

                    
                }
                
            }
            cout << "Maximum number of cycles reached. Game over." << endl;
                
            
  
        }
};

#endif