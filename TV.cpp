#include <iostream>
#include "TV.h"

using namespace std;

TV::TV(): screenSize(0){};

TV::TV(int powerRating, double screenSize): Appliance(powerRating), screenSize(screenSize){};

void TV::setScreenSize(double screenSize){
    this->screenSize = screenSize;
}

double TV::getScreenSize()const{
    return screenSize;
}

double TV::getPowerConsumption(){
    return (powerRating * (screenSize/10));
}


