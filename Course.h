#ifndef COURSE_H
#define COURSE_H

#include "Person.h"

class Course {
private:
    int id;
    std::string name;
    Person** persons; // Aggregation
    int numPersons;
public:
    Course(int id, std::string name);
    ~Course();
    // Other methods as needed
};

#endif // COURSE_H