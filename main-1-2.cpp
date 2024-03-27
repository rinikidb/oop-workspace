#include <iostream>
#include <string>
#include "Bike.h"
#include "Bike_yard.h"

using namespace std;

int main(){

    Bike_yard list1;
    cout << "Default capacity: " << list1.get_Total_Stock_Count() << endl;

    Bike b1("Honda", 21);
    Bike b2("B-twin", 22);
    Bike b3("Hercules", 25);

    int capacity = 4;
    Bike_yard list2(capacity);

    list2.add_Stock(b1);
    list2.add_Stock(b2);
    list2.add_Stock(b3);

    cout << "Current capacity: " << list2.get_Total_Stock_Count() << endl;

    cout << "Total number of bikes with the code 20 is: " << list2.get_Stock_Quantity(20) << endl;

    return 0;
}