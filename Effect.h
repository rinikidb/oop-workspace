#ifndef EFFECT_H
#define EFFECT_H

#include "GameEntity.h"


class Effect{
    public:
        virtual void apply(GameEntity& entity){}
};

#endif