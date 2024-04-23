#ifndef APPLIANCE_H
#define APPLIANCE_H

class Appliance{
    protected:
        int powerRating; 
        bool isON;
    
    public:
        Appliance();

        Appliance(int powerRating); //creates an Appliance with a power rating

        int get_powerRating() const;
        void set_powerRating(int powerRating);

        bool get_isOn();
        void turnOff();
        void turnOn();

        virtual double getPowerConsumption();

};
#endif 