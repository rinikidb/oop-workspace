#include <iostream>
#include <string>
#include "Bike.h"

using namespace std;

int main(){

    Bike b1;

    cout << "Default brand name: " << b1.getBrand() << endl;
    cout << "Default brand code: " << b1.getCode() << endl;

    Bike b2("Hercules", 25);

    cout << "Stored brand name: " << b2.getBrand() << endl;
    cout << "Stored brand code: " << b2.getCode() << endl;

    return 0;
}