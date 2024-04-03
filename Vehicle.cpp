#include <iostream>
#include <string>
#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int ID){
    this-> ID = ID;
    timeOfEntry = time(NULL);
}

int Vehicle::getID(){
        return ID;
    }

int Car::getParkingDuration(){
            currentTime = time(nullptr);
            duration = timeOfEntry - currentTime;
            //after reduction
            duration = duration - (0.1*duration);
            return duration;
        }

int Bus::getParkingDuration(){
            currentTime = time(nullptr);
            duration = timeOfEntry - currentTime;
            //after reduction
            duration = duration - (0.25*duration);
            return duration;
        }

int Motorbike::getParkingDuration(){
            currentTime = time(nullptr);
            duration = timeOfEntry - currentTime;
            //after reduction
            duration = duration - (0.15*duration);
            return duration;
        }
