#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

class AirVehicle{
    protected:
        int w; //in kgs
    public:

        int numberOfFlights;
        float fuel;//percentage

        AirVehicle();

        AirVehicle(int w);

        int get_w()const;

        void set_w(int w);

        int get_fuel()const;

        void set_fuel(int fuel);

        int get_numberOfFlights()const;

        void set_numberOfFlights(int numberOfFlights);

        void refuel();

        virtual void fly(int headwind, int minutes);

};

#endif