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
    for (int i = 0; i < total; i++){
        array[i] = new Vehicle(i);
    }


    return 0;
}