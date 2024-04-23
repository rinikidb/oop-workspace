#include <iostream>
#include "Fridge.h"

using namespace std;

int main(){

    Fridge fridge(300, 400);
    fridge.turnOn();
    cout << "Power Rating: " << fridge.get_powerRating() << endl;
    cout << "Is On: " << fridge.get_isOn() << endl;
    cout << "Volume: " << fridge.getVolume() << " liters" << endl;
    cout << "Power Consumption: " << fridge.getPowerConsumption() << " kWh/day" << endl;

    fridge.turnOff();
    fridge.set_powerRating(500);
    fridge.setVolume(400);
    cout << "New Power Rating: " << fridge.get_powerRating() << endl;
    cout << "Is On: " << fridge.get_isOn() << endl;
    cout << "New Volume: " << fridge.getVolume() << " liters" << endl;
    cout << "New Power Consumption: " << fridge.getPowerConsumption() << " kWh/day" << endl;

    return 0;
}