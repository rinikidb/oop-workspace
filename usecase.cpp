#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class Classroom{
    private:
        int class_size;
        Student* students_records;
    public:
        Classroom(){
            class_size = 0;
            students_records = new Student[class_size];
        };
        Classroom(int a_class_size){
            class_size = a_class_size;
            students_records = new Student[class_size];
        }
        ~Classroom(){
            delete[] students_records; 
        }
};

/*
Classroom::Classroom(){

}

Classroom::~Classroom(){

}
*/

int main(){

    Classroom oop2022(5);
    
    return 0;
}