#include <iostream>
#include "Fridge.h"

using namespace std;

int main(){

    Fridge Fridge(300,400);
    cout << "Original Volume: " << Fridge.getVolume() << " litres" << endl;
    cout << "Original Consumption: " << Fridge.getPowerConsumption() << " kWh/day" << endl;
    
    Fridge.setVolume(500);
    cout << "New Volume: " << Fridge.getVolume() << " litres" << endl;
    cout << "New Consumption: " << Fridge.getPowerConsumption() << " kWh/day" << endl;

    return 0;
}