#include <iostream>
#include "person.h"
using namespace std;

PersonList createPersonList(int n){
    PersonList array; 
    array.numPeople = n;
    array.people = new Person[n];

    for (int i = 0; i < n; i++){
        array.people[i].name = "Jane Doe";
        array.people[i].age = 1;
    }
    return array;
}