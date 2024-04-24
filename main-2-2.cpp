#include <iostream>
#include <string>
#include "Airplane.h"

using namespace std;

int main(){

    Airplane Airplane1(5800, 250);

    Airplane1.fly(40, 60);

    cout << "Weight: " << Airplane1.get_weight() << endl;
    cout << "Number of flights: " << Airplane1.get_numberOfFlights() << endl;
    cout << "Fuel: " << Airplane1.get_fuel() << "%" << endl;
    cout << "Number of passengers: " << Airplane1.get_numPassengers() << endl;
 

    Airplane Airplane2(5700, 300);

    Airplane2.fly(30, 60);

    cout << "Weight: " << Airplane2.get_weight() << endl;
    cout << "Number of flights: " << Airplane2.get_numberOfFlights() << endl;
    cout << "Fuel: " << Airplane2.get_fuel() << "%" << endl;
    cout << "Number of passengers: " << Airplane2.get_numPassengers() << endl;
 
    return 0;

    return 0;
}
