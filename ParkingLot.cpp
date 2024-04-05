#include "ParkingLot.h"
#include <iostream>

using namespace std;

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

int ParkingLot::getCount() const {
    return count;
}

void ParkingLot::parkVehicle(Vehicle* vehicle) {
  if (count < capacity) {
      vehicles[count++] = vehicle;
  }else{
        std::cout << "The lot is full" << std::endl;
  }
}

void ParkingLot::unparkVehicle(int ID) {
  bool found = false;
    for (int i = 0; i < count; ++i) {
      if (vehicles[i]->getID() == ID) {
          delete vehicles[i];
          for (int j = i; j < count - 1; ++j) {
              vehicles[j] = vehicles[j + 1];
          }
            
          --count;
          found = true;
          break;
      }
    }
    
    if (!found) {
      std::cout << "Vehicle not in the lot" << std::endl;
    }

}