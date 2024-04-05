#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"

#include <iostream>
#include <string>

using namespace std;

class Bus : public Vehicle{
    public:
        Bus(int ID) : Vehicle(ID) {}
        int getParkingDuration() const;
};

#endif