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
  int answer = 0;
  for (int i = 0; i < capacity; ++i) {
    if (vehicles[i] != nullptr && vehicles[i]->getID() == ID) {
      delete vehicles[i];
      vehicles[i] = nullptr;
      count--;
      answer = 1;
      break;
    }
  }

  if(answer == 1){
    std::cout << "Vehicle"  << " not in the lot" << std::endl;
  }
  else{
    std::cout << endl;
  }
}

int ParkingLot::countOverstayingVehicles(int maxDuration) const {
   
  int count = 0;
      
  time_t currentTime = time(nullptr);
      
  for (int i = 0; i < count; ++i) {
    if (difftime(currentTime, vehicles[i]->getTimeOfEntry()) > maxDuration){
      count++;
    }
  }
      
  return count;
}


/*
void ParkingLot::unparkVehicle(int vehicleID) {
    
    bool found = false;
     for (int i = 0; i < count; ++i) {
        if (vehicles[i]->getID() == vehicleID) {
             delete vehicles[i];
             for (int j = i; j < count - 1; ++j) {
                vehicles[j] = vehicles[j + 1];
            }
            
            --count;
            found = true;
            //std::cout << "Vehicle with ID " << vehicleID << " has been unparked." << std::endl;
            
            break;
        }
    }
    
    if (!found) {
        std::cout << "Vehicle"  << " not in the lot" << std::endl;
    }
}


int ParkingLot::countOverstayingVehicles(int maxParkingDuration) const {
   
    int count = 0;
    
    std::time_t currentTime = std::time(nullptr);
    
    for (int i = 0; i < count; ++i) {
        if (difftime(currentTime, vehicles[i]->getTimeOfEntry()) > maxParkingDuration) {
            ++count;
        }
    }
    
    return count;
}
*/