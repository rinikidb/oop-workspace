#ifndef MINE_H
#define MINE_H 

#include <iostream>
#include <tuple>
#include "GameEntity.h"
#include "Explosion.h"

using namespace std;

class Mine : public GameEntity{
    public:
        Mine(int x, int y):GameEntity(x,y,'M'){}
        Explosion explode(){
            type = 'X';
            return Explosion(get<0>(position), get<1>(position));   
        }
};

#endif
