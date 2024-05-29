#ifndef AVATAR_H
#define AVATAR_H

#include <iostream>
#include "GridUnit.h"

using namespace std;

class Avatar : public GridUnit{
    public:
        Avatar(int x, int y):GridUnit(x,y,'A'){}
        void shift(int dx, int dy){
            int new_x = get<0>(coordinates) + dx;
            int new_y = get<1>(coordinates) + dy;

            coordinates = make_tuple(new_x,new_y);
        }
};


#endif