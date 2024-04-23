#include <iostream>
#include "Appliance.h"

using namespace std;

int main(){

    Appliance appliance(100);
    appliance.turnOn();

    cout << "Power Rating: " << appliance.get_powerRating() << endl;
    cout << "Is On: " << appliance.get_isON() << endl;

    appliance.turnOff();
    cout << "Is On: " << appliance.get_isON() << endl;

    cout << "Power Consumption: " << appliance.getPowerConsumption() << endl;

    return 0;
}