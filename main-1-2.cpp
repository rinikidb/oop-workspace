#include <iostream>
#include "person.h"
using namespace std;

PersonList createPersonList(int n);

int main(){
    int n = 5;
    PersonList list = createPersonList(n);

    for (int i = 0; i < n; i++){
        cout << "Name: " << list.people[i].name << " | " << "Age: " << list.people[i].age << endl;
    }
    return 0;
}