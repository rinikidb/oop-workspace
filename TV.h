#ifndef TV_H
#define TV_H
#include "Appliance.h"

class TV : public Appliance{
    private:
        double screenSize; //in inches
    public:
        TV();

        TV(int powerRating, double screenSize);

        void setScreenSize(double screenSize);

        double getScreenSize()const;

        double getPowerConsumption()override;

};

#endif