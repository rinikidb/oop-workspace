#include <iostream>
#include <string>
#include "Bus.h"

using namespace std;

int Bus::getParkingDuration() const {
        time_t currentTime = time(nullptr);
        int duration = currentTime - timeOfEntry;
        //after reduction
        duration = duration - (0.1*duration);
        return static_cast<int>(duration);
            
}