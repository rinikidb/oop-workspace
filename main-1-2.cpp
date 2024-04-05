#include <iostream>
#include "Vehicle.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"
#include "ParkingLot.h"

int main() {
  // Create a ParkingLot object with a capacity of 10
  ParkingLot parkingLot(10);

  int choice;
  int ID;

  do {
    std::cout << "\nParking Lot Menu:\n";
    std::cout << "1. Park a vehicle\n";
    std::cout << "2. Unpark a vehicle\n";
    std::cout << "3. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "\nEnter vehicle type (1 - Car, 2 - Bus, 3 - Motorbike): ";
        std::cin >> choice;
        if (choice == 1) {
          parkingLot.parkVehicle(new Car((parkingLot.getCount()+1)));
        } else if (choice == 2) {
          parkingLot.parkVehicle(new Bus((parkingLot.getCount()+1)));
        } else if (choice == 3) {
          parkingLot.parkVehicle(new Motorbike((parkingLot.getCount()+1)));
        } else {
          std::cout << "Invalid choice.\n";
        }
        break;
      case 2:
        std::cout << "Enter the ID of the vehicle to unpark: ";
        std::cin >> ID;
        parkingLot.unparkVehicle(ID);
        break;
      case 3:
        break;
      default:
        std::cout << "Invalid choice.\n";
    }
  } while (choice != 3);

  return 0;
}