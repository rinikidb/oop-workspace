#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "GameEntity.h"

using namespace std;

class Ship : public GameEntity{
    public:
        Ship(int x, int y):GameEntity(x,y,'S'){}
 
        void move(int dx, int dy){ 
            int new_x = get<0>(position) + dx;
            int new_y = get<1>(position) + dy;

            position = make_tuple(new_x,new_y);
        }
};

#endif