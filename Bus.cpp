#include <iostream>
#include <string>
#include "Bus.h"

using namespace std;

int Bus::getParkingDuration(){
            /*
            currentTime = time(nullptr);
            duration = timeOfEntry - currentTime;
            //after reduction
            duration = duration - (0.1*duration);
            return duration;
            */

            time_t currentTime = time(nullptr);
            int duration = difftime(currentTime, timeOfEntry);
            return duration * 0.9;
        }