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
        int getID() const;
        virtual ~Vehicle(){};
        time_t getTimeOfEntry() const;
        
};

#endif 