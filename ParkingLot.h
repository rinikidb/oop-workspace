#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"

class ParkingLot {
private:
  Vehicle** vehicles;
  int capacity;
  int count;

public:
  ParkingLot(int capacity);
  ~ParkingLot();
  int getCount() const { return count; }
  bool parkVehicle(Vehicle* vehicle);
  bool unparkVehicle(int ID);
};

#endif