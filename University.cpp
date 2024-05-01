#include <iostream>
#include "University.h"

using namespace std;

University::University(string name, string location){
    this->name = name;
    this->location = location;
    courses = nullptr;
    numCourses = 0;
}

University::~University(){
    delete[] courses; // Assuming dynamic allocation of courses
}

void University::addCourse(int id, string name){
    // Implement course addition
}