#include <iostream>
#include <string>
#include "Helicopter.h"

using namespace std;

int main(){

    Helicopter Helicopter1(5800, "racer");

    Helicopter1.fly(40, 60);

    cout << "Weight: " << Helicopter1.get_weight() << endl;
    cout << "Number of flights: " << Helicopter1.get_numberOfFlights() << endl;
    cout << "Fuel: " << Helicopter1.get_fuel() << "%" << endl;
    Helicopter1.get_name();

    Helicopter Helicopter2(5700, "racer");

    Helicopter2.fly(30, 60);

    cout << "Weight: " << Helicopter2.get_weight() << endl;
    cout << "Number of flights: " << Helicopter2.get_numberOfFlights() << endl;
    cout << "Fuel: " << Helicopter2.get_fuel() << "%" << endl;
    Helicopter2.get_name();

    return 0;
}