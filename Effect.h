#ifndef EFFECT_H
#define EFFECT_H

#include <iostream>
#include "GameEntity.h"

using namespace std;

class Effect{
    public:
        virtual void apply(GameEntity& entity){};  
};

#endif