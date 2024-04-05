#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

#include <iostream>
#include <string>

using namespace std;

class Car : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        Car(int ID) : Vehicle(ID) {}
        int getParkingDuration();
        
};

#endif