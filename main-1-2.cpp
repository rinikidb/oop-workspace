#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
    ParkingLot parkingLot(3); 
    

    int choice = 0;
    
    while (true) {
        
        std::cout << "Enter the type of vehicle to park (1. Car, 2. Bus, 3. Motorbike, 0. Exit): ";
        std::cin >> choice;
        
        if (choice == 0) {
            break;
        }
        
        int id;
        
        std::cout << "Enter the ID of the vehicle: ";
        std::cin >> id;
        Vehicle* vehicle = nullptr;
        if (choice == 1) {
            vehicle = new Car(id);
        } else if (choice == 2) {
            vehicle = new Bus(id);
        } else if (choice == 3) {
            vehicle = new Motorbike(id);
        }
        if (vehicle) {
            parkingLot.parkVehicle(vehicle);
        }
    }


    
    Car* extraCar = new Car(4);
    parkingLot.parkVehicle(extraCar);

   

    int idToUnpark;
    
    std::cout << "Enter the ID of the vehicle to unpark: ";
    std::cin >> idToUnpark;
    parkingLot.unparkVehicle(idToUnpark);
    
    //std::cout << "Attempting to unpark a vehicle that is not in the lot..." << std::endl;
    //parkingLot.unparkVehicle(100);
    

    return 0;
}
