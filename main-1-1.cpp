#include <iostream>
#include <string>
#include "Vehicle.h"

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
    for (int i = 0; i < numCars; ++i){
        vehicles[i] = new Car(i + 1);
    }
    for (int i = numCars; i < numCars + numBuses; ++i){
        vehicles[i] = new Bus(i + 1);
    }
    for (int i = numCars + numBuses; i < numCars + numBuses + numMotorbikes; ++i){
        vehicles[i] = new Motorbike(i + 1);
    }


    for (int i = 0; i < total; i++) {
        cout << "Vehicle ID " << vehicles[i]->getID() << " parking duration: " << vehicles[i]->getParkingDuration() << " seconds\n" << endl;
  
    }

    // Deallocate memory
    for (int i = 0; i < numCars + numBuses + numMotorbikes; ++i){
        delete vehicles[i];
    }

    return 0;
}