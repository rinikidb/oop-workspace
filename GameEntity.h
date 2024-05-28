#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <iostream>
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
        tuple<int, int> getPos(){
            return position;
        }
        char get_type(){
            return type;
        }
        void set_type(char type){
            this->type = type; 
        }
        void set_position(int x, int y){
            position = make_tuple(x,y); 
        }

};

#endif