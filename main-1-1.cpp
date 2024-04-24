#include <iostream>
#include "AirVehicle.h"

using namespace std;

int main(){

    AirVehicle AirVehicle(500);
    cout << "Weight of the Air Vehicle is: " << AirVehicle.get_w() << "kgs" << endl;
    cout << "Number of flights initially: " << AirVehicle.get_numberOfFlights() << endl;
    cout << "Fuel initially: " << AirVehicle.get_fuel() << "%" << endl;

    AirVehicle.fly(500, 50);
    AirVehicle.set_fuel(50);
    AirVehicle.set_w(450);

    cout << "Number of flights now: " << AirVehicle.get_numberOfFlights() << endl;
    cout << "New Weight of the Air Vehicle is: " << AirVehicle.get_w() << "kgs" << endl;
    cout << "Fuel now: " << AirVehicle.get_fuel() << "%" << endl;

    AirVehicle.refuel();

    cout << "Fuel after refuelling: " << AirVehicle.get_fuel() << "%" <<  endl;

    return 0;
}