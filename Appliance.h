#ifndef APPLIANCE_H
#define APPLIANCE_H

class Appliance{
    private:
        int powerRating;
        bool isON;
    
    public:
        Appliance();

        Appliance(int powerRating); //creates an Appliance with a power rating

        int get_powerRating() const;
        void set_powerRating(int powerRating);

        bool get_isON();
        void turnOff();
        void turnOn();

        virtual double getPowerConsumption();

};
#endif 