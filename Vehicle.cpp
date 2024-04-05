#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Car.h"

using namespace std;

Vehicle::Vehicle(int ID){
    this-> ID = ID;
    timeOfEntry = time(NULL);
}

int Vehicle::getID(){
        return ID;
    }

time_t Vehicle::getTimeOfEntry() const {
    return timeOfEntry; 
}

int Car::getParkingDuration(){
        currentTime = time(nullptr);
        duration = currentTime - timeOfEntry;
        //after reduction
        duration = duration - (0.1*duration);
        return duration;
            
            /*
            time_t currentTime = time(nullptr);
            int duration = difftime(currentTime, timeOfEntry);
            return duration * 0.9;
            */
}