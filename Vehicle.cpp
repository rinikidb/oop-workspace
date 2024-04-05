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
