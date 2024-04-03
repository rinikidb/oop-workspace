#include <iostream>
#include <string>

using namespace std;

class Vehicle{
    protected:
        time_t timeOfEntry;
        int ID;

    public:
        Vehicle(int ID){
            this-> ID = ID;
            timeOfEntry = time(NULL);
        }

        int getID(){
            return ID;
        }
};

class Car : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration(){
            currentTime = time(nullptr);
            duration = difftime(currentTime, timeOfEntry);
            //after reduction
            duration = duration - (0.1*duration);
            return duration;
        }
        
};

class Bus : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration(){
            currentTime = time(nullptr);
            duration = difftime(currentTime, timeOfEntry);
            //after reduction
            duration = duration - (0.25*duration);
            return duration;
        }
        
};

class Motorbike : public Vehicle{
    private:
        time_t currentTime;
        int duration;
    public:
        int getParkingDuration(){
            currentTime = time(nullptr);
            duration = difftime(currentTime, timeOfEntry);
            //after reduction
            duration = duration - (0.15*duration);
            return duration;
        }
        
};