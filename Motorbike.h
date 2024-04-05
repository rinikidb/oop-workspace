#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

#include <iostream>
#include <string>

using namespace std;

class Motorbike : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        Motorbike(int ID) : Vehicle(ID) {}
        int getParkingDuration();
        
};

#endif