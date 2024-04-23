#include <iostream>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

using namespace std;

int main() {
    House house(3);

    Fridge fridge(300,400);
    TV tv(100,48);

    house.addAppliance(&fridge);
    house.addAppliance(&tv);

    cout << "Total Power Consumption of the House: " << house.getTotalPowerConsumption() << " kWh/day" << endl;

    return 0;
}