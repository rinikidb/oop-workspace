#include <iostream>
#include <string>
#include "Bike.h"

using namespace std;

int main(){

    Bike b1;

    cout << "Default brand name: " << b1.get_brand() << endl;
    cout << "Default brand code: " << b1.get_code() << endl;

    Bike b2("Hercules", 25);

    cout << "Stored brand name: " << b2.get_brand() << endl;
    cout << "Stored brand code: " << b2.get_code() << endl;

    return 0;
}