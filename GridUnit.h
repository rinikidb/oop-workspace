#ifndef GRIDUNIT_H
#define GRIDUNIT_H

#include <iostream>
#include <tuple>

using namespace std;

class GridUnit{
    protected:
        tuple<int, int> coordinates;
        char entity;
    public:
        GridUnit(int x, int y, char entity){
            coordinates = make_tuple(x,y);
            this->entity = entity;
        }

        std::tuple<int, int> getCoordinates(){
            return coordinates;
        }

        char getEntity(){
            return entity; 
        }

        void setCoordinates(int x, int y){
            coordinates = make_tuple(x,y);
        }

        void setEntity(char entity){
            this->entity = entity;
        }

};

#endif