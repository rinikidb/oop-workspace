#include <iostream>
#include "University.h"

int main() {
    // Create a university
    University myUniversity("MyUni", "Location");

    // Add a course to the university
    myUniversity.addCourse(1, "Course 1");

    // Add a student to the course
    // Assuming appropriate methods in Course class

    // Add a grade for the student for some assignments
    // Assuming appropriate methods in Gradebook class

    return 0;
}