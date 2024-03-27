#include <iostream>
#include <string>
#include "Bike.h"

using namespace std;

Bike::Bike(){
    brand = "";
    code = 0;
}

Bike::Bike(string brand, int code){
    this->brand = brand;
    this->code = code;
}

string Bike::getBrand(){
    return brand;
}

int Bike::getCode(){
    return code;
}

Bike::~Bike(){
    
}