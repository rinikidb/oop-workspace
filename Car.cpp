#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

int Car::getParkingDuration(){
            currentTime = time(nullptr);
            duration = timeOfEntry - currentTime;
            //after reduction
            duration = duration - (0.1*duration);
            return duration;
        }