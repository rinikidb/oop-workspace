#include <iostream>
#include "person.h"
using namespace std;

PersonList deepCopyPersonList(PersonList pl){
    PersonList list;
    list.numPeople = pl.numPeople;
    list.people = new Person[pl.numPeople];

    for (int i = 0; i < pl.numPeople; i++){
        list.people[i].name = pl.people[i].name;
        list.people[i].age = pl.people[i].age;
    }
    return list;
}