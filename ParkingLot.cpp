#include "ParkingLot.h"
#include <iostream>

ParkingLot::ParkingLot(int capacity) : capacity(capacity), count(0) {
  vehicles = new Vehicle*[capacity];
  for (int i = 0; i < capacity; i++) {
    vehicles[i] = nullptr;
  }
}

ParkingLot::~ParkingLot() {
  for (int i = 0; i < capacity; i++) {
    delete vehicles[i];
  }
  delete[] vehicles;
}

bool ParkingLot::parkVehicle(Vehicle* vehicle) {
  if (count < capacity) {
        vehicles[count++] = vehicle;
    } else  {
        std::cout << "The lot is full" << std::endl;
    }

  return false;
}

bool ParkingLot::unparkVehicle(int ID) {
   for (int i = 0; i < capacity; i++) {
    if (vehicles[i] != nullptr && vehicles[i]->getID() == ID) {
      delete vehicles[i];
      vehicles[i] = nullptr;
      count--;
      return true;
    }
  }

  std::cout << "Vehicle not in the lot.\n";
  return false;
}