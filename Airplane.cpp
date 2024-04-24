#include <iostream>
#include <string>
#include "Airplane.h"

using namespace std;

Airplane::Airplane(): w(0), p(0){};

Airplane::Airplane(int w, int p): w(w), p(p){};

int Airplane::get_weight(){
    return w;
}

void Airplane::reducePassengers(int x){
    numPassengers = numPassengers - x;
    if(numPassengers < 0){
        numPassengers = 0;
    }
}

int Airplane::get_numPassengers(){
    return numPassengers;
}

void Airplane::fly(int headwind, int minutes){
    while(fuel > 20){
        if(headwind >= 60){
            for(int i = 1; i < minutes+1; i++){
                fuel = fuel - (0.005*fuel) - ((0.000001)*numPassengers*fuel);
            }
        }else{
            for(int i = 1; i < minutes+1; i++){
                fuel = fuel - (0.025*fuel) - ((0.000001)*numPassengers*fuel);
            }
        }
        numberOfFlights++;
    }
    
}

