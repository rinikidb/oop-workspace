#include <iostream>
#include <string>
#include "Bike.h"
#include "Bike_yard.h"

using namespace std;

Bike_yard::Bike_yard(){
    total_capacity = 0;
    current_capacity = 0;
    bike_list = new Bike[total_capacity];
}

Bike_yard::Bike_yard(int capacity){
    total_capacity = capacity;
    current_capacity = 0;
    bike_list = new Bike[total_capacity];
}

int Bike_yard::get_Total_Stock_Count(){
    return current_capacity;
}

int Bike_yard::get_Stock_Quantity(int code){
    int count = 0;
    for (int i = 0; i < current_capacity; i++){
        if (bike_list[i].getCode() == code){
            count = count + 1;
        }
    }
    return count;
}

Bike* Bike_yard::get_Current_Stock_List(){
    return bike_list; 
}

bool Bike_yard::add_Stock(Bike b){ 
    if (current_capacity < total_capacity){
        bike_list[current_capacity] = b;
        current_capacity++;
        return true;
    }
    return false;
}

Bike_yard::~Bike_yard(){
    delete[] bike_list;
}

