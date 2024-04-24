#include <iostream>
#include "House.h"
#include "Fridge.h"
#include "TV.h"

using namespace std;

int main() {
    House house(3);

    Fridge fridge(300,400);
    TV tv(100,48);
    Fridge fridge2(200,300);
    TV tv2(100,56);

    house.addAppliance(&fridge);
    house.addAppliance(&tv);
    house.addAppliance(&fridge2);
    house.addAppliance(&tv2);

    cout << "Total Power Consumption of the House: " << house.getTotalPowerConsumption() << " kWh/day" << endl;

    return 0;
}