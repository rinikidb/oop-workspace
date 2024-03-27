#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>

using namespace std;

class Bike{
    private:
        string brand;
        int code;
    public:
        Bike();
        
        Bike(string brand, int code);

        string get_brand();

        int get_code();

        ~Bike();
};

#endif
