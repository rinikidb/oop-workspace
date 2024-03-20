#include <iostream>
#include "person.h"
using namespace std;

PersonList deepCopyPersonList(PersonList pl);

int main(){
    PersonList list1;
    list1.numPeople = 5;
    list1.people = new Person[list1.numPeople];
    for (int i = 0; i < list1.numPeople; i++){
        list1.people[i].name = "John Doe";
        list1.people[i].age = 1;
    }

    PersonList list2 = deepCopyPersonList(list1);

    cout << "Copied list:" << endl;

    for (int i = 0; i < list2.numPeople; i++){
        cout << "Name: " << list2.people[i].name << " | " << "Age: " << list2.people[i].age << endl;
    }
    delete[] list1.people;
    delete[] list2.people;
    return 0;
}