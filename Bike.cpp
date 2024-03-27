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

string Bike::get_brand(){
    return brand;
}

int Bike::get_code(){
    return code;
}

Bike::~Bike(){
    
}