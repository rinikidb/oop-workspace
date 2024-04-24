#include <iostream>
#include "House.h"

using namespace std;

House::House(): appliances(nullptr), numAppliances(0){};

House::House(int numAppliances): numAppliances(numAppliances){
    appliances = new Appliance*[numAppliances];
    for(int i = 0; i < numAppliances; i ++){
        appliances[i] = nullptr;
    }
}

House::~House(){
    delete[] appliances;
}

bool House::addAppliance(Appliance* appliance){
    for(int i = 0; i < numAppliances; i++){
        if (appliances[i] == nullptr){
            appliances[i] = appliance;
            cout << "Appliance added successfully." << endl;
            return true;
            break;
        }
    }
    cout << "Error: No space for more appliance!" << endl;
    return false;
}

double House::getTotalPowerConsumption(){
    double totalPowerConsumption = 0.0;
    for(int i = 0; i < numAppliances; i++){
        if(appliances[i] != nullptr){
            totalPowerConsumption += appliances[i]->getPowerConsumption();
        }
    }
    return totalPowerConsumption;
}