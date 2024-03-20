#include <iostream>
#include "person.h"
using namespace std;

Person* createPersonArray(int n);

int main(){
    int n = 5;
    Person* persons = createPersonArray(n);

    for (int i = 0; i < n; i++){
        cout << "Name: " << persons[i].name << " | " << "Age: " << persons[i].age << endl;
    }
    delete[] persons;
    return 0;
}