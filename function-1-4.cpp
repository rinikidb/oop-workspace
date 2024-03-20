#include <iostream>
#include "person.h"
using namespace std;

PersonList shallowCopyPersonList(PersonList pl){
    PersonList list;
    list.numPeople = pl.numPeople;
    list.people = pl.people;

    return list;
}

