#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <string>
#include "AirVehicle.h"

class Airplane : public AirVehicle{ 
    private:
        int numPassengers;
        int w;
        int p; 
    public:
        Airplane();

        Airplane(int w, int p);

        void reducePassengers(int x);   // reduce passenger list by x

        int get_numPassengers();

        int get_weight();

        void fly(int headwind, int minutes)override; 

}; 



#endif