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
  int getCount() const;
  void parkVehicle(Vehicle* vehicle);
  void unparkVehicle(int ID);
  int countOverstayingVehicles(int maxParkingDuration) const;
};

#endif