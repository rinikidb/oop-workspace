#ifndef HELICOPTER_H
#define HELICOPTER_H
#include <string>
#include "AirVehicle.h"

using namespace std;

class Helicopter : public AirVehicle{
    private:
        int w; 
        string name;  
    public:
        Helicopter();

        Helicopter(int w, string n);

        int get_weight();

        void fly(int headwind, int minutes)override;

};

#endif