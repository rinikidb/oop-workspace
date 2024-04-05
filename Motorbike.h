#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

#include <iostream>
#include <string>

using namespace std;

class Motorbike : public Vehicle{
    public:
        Motorbike(int ID) : Vehicle(ID) {}
        int getParkingDuration() const;
        
};

#endif