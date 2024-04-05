#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

using namespace std;

int main() {
    int numCars, numBuses, numMotorbikes;
    cout << "Enter the number of cars: ";
    cin >> numCars;
    cout << "Enter the number of buses: ";
    cin >> numBuses;
    cout << "Enter the number of motorbikes: ";
    cin >> numMotorbikes;

    //Vector to hold pointers to Vehicle objects
    vector<Vehicle*> array;

    //Creating Car objects 
    for (int i = 0; i < numCars; ++i) {
        array.push_back(new Car(i + 1));
    }

    //Creating Bus objects 
    for (int i = 0; i < numBuses; ++i) {
        array.push_back(new Bus(i + 1));
    }

    //Creating Motorbike objects 
    for (int i = 0; i < numMotorbikes; ++i) {
        array.push_back(new Motorbike(i + 1));
    }

    //Printing it out
    for (auto vehicle : array) {
        std::cout << "Vehicle " << vehicle->getID() << " parking duration: ";
        //Checking the type of vehicle
        if (Car* car = dynamic_cast<Car*>(vehicle)) {
            std::cout << car->getParkingDuration();
        } else if (Bus* bus = dynamic_cast<Bus*>(vehicle)) {
            std::cout << bus->getParkingDuration();
        } else if (Motorbike* motorbike = dynamic_cast<Motorbike*>(vehicle)) {
            std::cout << motorbike->getParkingDuration();
        }
        std::cout << " seconds" << std::endl;
    }

    //Deallocation of memory
    for (auto vehicle : array) {
        delete vehicle;
    }

    return 0;
}
