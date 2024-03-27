#ifndef BIKE_YARD_H
#define BIKE_YARD_H

#include <iostream>
#include <string>
#include "Bike.h"

using namespace std;


class Bike_yard{
    private:
        int total_capacity;
        int current_capacity;
        Bike* bike_list;

    public:
        Bike_yard();

        Bike_yard(int capacity);

        int get_Total_Stock_Count();

        int get_Stock_Quantity(int code);

        Bike *get_Current_Stock_List();

        bool add_Stock(Bike b);

        ~Bike_yard();
};

#endif