#include <iostream>
#include "person.h"
using namespace std;

PersonList shallowCopyPersonList(PersonList pl);

int main(){
    PersonList list3;
    list3.numPeople = 5;
    list3.people = new Person[list3.numPeople];
    for (int i = 0; i < list3.numPeople; i++){
        list3.people[i].name = "John Doe";
        list3.people[i].age = i;
    }

    PersonList list4 = shallowCopyPersonList(list3);

    cout << "Copied list:" << endl;

    for (int i = 0; i < list4.numPeople; i++){
        cout << "Name: " << list4.people[i].name << " | " << "Age: " << list4.people[i].age << endl;
    }
    delete[] list3.people;

    return 0;
}