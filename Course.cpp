#include <iostream>
#include "Course.h"

using namespace std;

Course::Course(int id, string name){
    this->id = id;
    this->name = name;
    persons = nullptr;
    numPersons = 0;
}

Course::~Course(){
    delete[] persons; // Assuming dynamic allocation of persons
}

// Implement other methods as needed