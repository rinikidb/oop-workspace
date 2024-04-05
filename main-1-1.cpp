#include <iostream>
#include <vector>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    int numCars, numBuses, numMotorbikes;
    std::cout << "Enter the number of cars: ";
    std::cin >> numCars;
    std::cout << "Enter the number of buses: ";
    std::cin >> numBuses;
    std::cout << "Enter the number of motorbikes: ";
    std::cin >> numMotorbikes;

    // Vector to hold pointers to Vehicle objects
    std::vector<Vehicle*> vehicles;

    // Creating Car objects and adding pointers to them in the vector
    for (int i = 0; i < numCars; ++i) {
        vehicles.push_back(new Car(i + 1));
    }

    // Creating Bus objects and adding pointers to them in the vector
    for (int i = 0; i < numBuses; ++i) {
        vehicles.push_back(new Bus(i + 1));
    }

    // Creating Motorbike objects and adding pointers to them in the vector
    for (int i = 0; i < numMotorbikes; ++i) {
        vehicles.push_back(new Motorbike(i + 1));
    }

    // Printing parking durations for each vehicle
    for (auto vehicle : vehicles) {
        std::cout << "Vehicle " << vehicle->getID() << " parking duration: ";
        // Check if the vehicle is a Car, Bus, or Motorbike to call the correct method
        if (Car* car = dynamic_cast<Car*>(vehicle)) {
            std::cout << car->getParkingDuration();
        } else if (Bus* bus = dynamic_cast<Bus*>(vehicle)) {
            std::cout << bus->getParkingDuration();
        } else if (Motorbike* motorbike = dynamic_cast<Motorbike*>(vehicle)) {
            std::cout << motorbike->getParkingDuration();
        }
        std::cout << " seconds" << std::endl;
    }

    // Freeing memory allocated for vehicles
    for (auto vehicle : vehicles) {
        delete vehicle;
    }

    return 0;
}
