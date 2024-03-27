#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

/*
Student* studentFactory(){
    Student* k = new Student();
    return k;
}
*/

Student* foo(){
    //Student s1;
    Student* a = new Student[5];

    return a;
}

int main(){

    Student* a = foo();

    /*
    Student* p = studentFactory();

    p->set_grade(96.00);

    cout << p->get_name() << endl;
    cout << p->get_grade() << endl;
    */

    //Student* a = new Student[5];

    
    for (int i = 0; i < 5; i++){
        cout << a[i].get_name() << endl;
    }
    
    delete[] a;

    return 0;
}