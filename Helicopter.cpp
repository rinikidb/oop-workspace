#include <iostream>
#include <string>
#include "Helicopter.h"

using namespace std;

Helicopter::Helicopter(): w(0), name(" "){};

Helicopter::Helicopter(int w, string n): w(w), name(n){};

int Helicopter::get_weight(){
    return w;   
}

string Helicopter::get_name(){
    return name;
}
void Helicopter::fly(int headwind, int minutes){
    while (fuel > 20){
        if(w > 5670){
            if(headwind <= 40){
                for(int i = 1; i < minutes+1; i++){
                    fuel = fuel - (0.005*fuel);
                }
            }else{
                for(int i = 1; i < minutes+1; i++){
                    fuel = fuel - (0.019*fuel);
                }
            }

        }else{
            if(headwind >= 40){
                for(int i = 1; i < minutes+1; i++){
                    fuel = fuel - (0.004*fuel);
                }
            }else{
                for(int i = 1; i < minutes+1; i++){
                    fuel = fuel - (0.018*fuel);
                }
            }
        }
        numberOfFlights++;
    }
    
}