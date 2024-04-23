#include "House.h"
#include <iostream>

using namespace std; 

House::House(): appliances(nullptr), numAppliances(0){}

House::House(int numAppliances): numAppliances(numAppliances){
    appliances = new Appliance*[numAppliances];
    for (int i = 0; i < numAppliances; ++i) {
        appliances[i] = nullptr; // Initialize all pointers to nullptr
    }
}

House::~House(){
    delete[] appliances; // Deallocate the array
}

bool House::addAppliance(Appliance* appliance) {
   for (int i = 0; i < numAppliances; i++) {
        if (appliances[i] == nullptr) {
            appliances[i] = appliance;
            return true;
        }
    }
    cout << "Error: No space for more appliances!" << endl;
    return false;
}

double House::getTotalPowerConsumption() {
    double totalPowerConsumption = 0.0;
    for (int i = 0; i < numAppliances; ++i) {
        if (appliances[i] != nullptr) {
            totalPowerConsumption += appliances[i]->getPowerConsumption();
        }
    }
    return totalPowerConsumption;
}