#ifndef HOUSE_H
#define HOUSE_H
#include "Appliance.h"

class House{
    private:
        int numAppliances;
        Appliance** appliances;
    public:
        House(); //creates an empty object

        House(int numAppliances); //creates a House object with space for numAppliances appliances

        bool addAppliance(Appliance* appliance); //adds an Appliance object to the house 
        //return true if there is space in the house otherwise false

        double getTotalPowerConsumption();

        ~House();
};      


#endif