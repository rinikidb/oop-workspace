#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

class AirVehicle{
    protected:
        int w; //in kgs
        int numberOfFlights;
        float fuel;//percentage
    public:

        AirVehicle();

        AirVehicle(int w);

        int get_weight()const;

        void set_weight(int w);

        int get_fuel()const;

        void set_fuel(int fuel);

        int get_numberOfFlights()const;

        void set_numberOfFlights(int numberOfFlights);

        void refuel();

        virtual void fly(int headwind, int minutes);

};

#endif