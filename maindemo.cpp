#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Bus.h"
#include "Car.h"
#include "Motorbike.h"

using namespace std;

int main(){

    int numCars;
    int numBuses;
    int numMotorbikes;

    cout << "Enter the number of cars you want to enter: " <<endl;
    cin >> numCars;
    cout << "Enter the number of buses you want to enter: " <<endl;
    cin >> numBuses;
    cout << "Enter the number of motorbikes you want to enter: " <<endl;
    cin >> numMotorbikes;

    int total = numCars + numBuses + numMotorbikes; 

    Vehicle* array[total];
    
    
  // Create Car, Bus, and Motorbike objects based on user input
    for (int i = 0; i < numCars; ++i) {
        array[i] = new Car(i + 1);
    }
    for (int i = numCars; i < numCars + numBuses; ++i) {
        array[i] = new Bus(i + 1);
    }
    for (int i = numCars + numBuses; i < numCars + numBuses + numMotorbikes; ++i) {
        array[i] = new Motorbike(i + 1);
    }

    // Iterate through the array and call getParkingDuration() for each vehicle
    for (int i = 0; i < total; ++i) {
        cout << "Vehicle ID " << array[i]->getID() << " parking duration: " << array[i]->getParkingDuration() << " seconds\n" << endl;
    }

    // Deallocate memory
    for (int i = 0; i < total; ++i){
        delete array[i];
    }

    return 0;
}