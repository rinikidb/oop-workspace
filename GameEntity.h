#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class GameEntity{
    protected:
        tuple<int, int> position;  
        char type; 
    public:
        GameEntity(int x, int y, char type){
            this->position = make_tuple(x,y);
            this->type = type;
        }
        std::tuple<int, int> getPos(){
            return position;
        }
        char getType(){
            return type;
        }
        void setType(char type){
            this->type = type;
        }
        void setPos(int x, int y){
            position = make_tuple(x,y);
        }
};

#endif