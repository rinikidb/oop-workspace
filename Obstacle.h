#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <iostream>
#include "GridUnit.h"
#include "Modifier.h"

using namespace std;

class Obstacle : public GridUnit, public Modifier{
    protected:
        bool active;
    public:
        Obstacle(int x, int y):GridUnit(x,y,'O'){
            active = true;
        }
        bool isActive(){
            if (active){
                return true;
            }
            else{
                return false;
            }
        }
        void apply(GridUnit& unit){
            unit.setEntity('O');
            active = false;
        }



};

#endif 