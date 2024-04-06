#include <iostream>
#include <string>
#include "Vehicle.h"


using namespace std;

Vehicle::Vehicle(int ID){
    this-> ID = ID;
    timeOfEntry = time(nullptr);
}

int Vehicle::getID() const {
        return ID;
}

time_t Vehicle::getTimeOfEntry() const {
    return timeOfEntry; 
}