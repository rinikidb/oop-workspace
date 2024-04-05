#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

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