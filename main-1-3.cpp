#include <iostream>

#include "ParkingLot.h"
#include "Car.h"
#include "Bus.h"
#include "Motorbike.h"

int main() {
    ParkingLot parkingLot(10); 

    
    for (int i = 0; i < 5; i++) {
        parkingLot.parkVehicle(new Car(i+1));
    }

    
    for (int i = 0; i < 3; i++) {
        parkingLot.parkVehicle(new Bus(i+6));
    }

    
    for (int i = 0; i < 2; i++) {
        parkingLot.parkVehicle(new Motorbike(i+9));
    }


    
    int overStayingCount = parkingLot.countOverstayingVehicles(15);
    std::cout << "Number of vehicles overstaying in the parking lot: " << overStayingCount << std::endl;

    return 0;
}