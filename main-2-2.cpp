#include <iostream>
#include "TV.h"

using namespace std;

int main(){

    TV TV(300,56);
    TV.turnOn();
    cout << "Power Rating: " << TV.get_powerRating() << endl;
    cout << "Is On: " << TV.get_isOn() << endl;
    cout << "Screen Size: " << TV.getScreenSize() << "inches" << endl;
    cout << "Power Consumption: " << TV.getPowerConsumption() << " kWh/day" << endl;

    TV.setScreenSize(48);
    TV.turnOff();
    TV.set_powerRating(400);
    cout << "New Power Rating: " << TV.get_powerRating() << endl;
    cout << "Is On: " << TV.get_isOn() << endl;
    cout << "New Screen Size: " << TV.getScreenSize() << "inches" << endl;
    cout << "New Power Consumption: " << TV.getPowerConsumption() << " kWh/day" << endl;


    return 0;
}