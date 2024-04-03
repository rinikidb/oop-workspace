#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    protected:
        time_t timeOfEntry;
        int ID;

    public:
        Vehicle(int ID);
        int getID();
};

class Car : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration();
        
};

class Bus : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration();
};

class Motorbike : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration();
        
};

#endif 