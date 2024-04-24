#include <iostream>
#include "AirVehicle.h"

using namespace std;

AirVehicle::AirVehicle(): w(0), numberOfFlights(0), fuel(100){};

AirVehicle::AirVehicle(int w): w(w), numberOfFlights(0), fuel(100){};

int AirVehicle::get_w()const{
    return w;
}

void AirVehicle::set_w(int w){
    this->w = w;
}

int AirVehicle::get_fuel()const{
    return fuel;
}

void AirVehicle::set_fuel(int fuel){
    this->fuel = fuel;
}

int AirVehicle::get_numberOfFlights()const{
    return numberOfFlights;
}

void AirVehicle::set_numberOfFlights(int numberOfFlights){
    this->numberOfFlights = numberOfFlights;
}

void AirVehicle::refuel(){
    fuel = 100; //in percentage
}

void AirVehicle::fly(int headwind, int minutes){
    numberOfFlights++;
}