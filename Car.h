#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

#include <iostream>
#include <string>

using namespace std;

class Car : public Vehicle{
    public:
        Car(int ID) : Vehicle(ID) {}
        int getParkingDuration() const;
        
};

#endif