#include <iostream>
#include "Appliance.h"

using namespace std;

Appliance::Appliance(): powerRating(0), isON(false){};

Appliance::Appliance(int powerRating): powerRating(powerRating), isON(false){};

int Appliance::get_powerRating() const{
    return powerRating;
}

void Appliance::set_powerRating(int powerRating){
    this->powerRating = powerRating;
}

bool Appliance::get_isOn(){
    return isON;
}

void Appliance::turnOff(){
    isON = false;
}

void Appliance::turnOn(){
    isON = true;
}

double Appliance::getPowerConsumption(){
    return 0.0;
}


