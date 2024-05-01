#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>
#include "Course.h"

using namespace std; 

class University{

    private: 
        string name;
        string location;
        Course* courses; // Aggregation
        int numCourses;
    public:
        University(string name, string location);
        ~University();
        void addCourse(int id, string name); 
};



#endif