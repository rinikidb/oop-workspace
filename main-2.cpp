#include <iostream>
#include "Obstacle.h"
#include "Avatar.h"

using namespace std;

int main(){

    GridUnit gridUnit(8,9,'R');

    Obstacle obstacle(5,6);
    cout << "Initial Status" << endl; 
    cout << "Coordinates: (" << get<0>(obstacle.getCoordinates()) << "," << get<1>(obstacle.getCoordinates()) << ")" << endl;
    cout << "Type: " << obstacle.getEntity() << endl;

    obstacle.apply(gridUnit);

    Avatar avatar(1,2);
    cout << "Initial Avatar Coordinates: (" << get<0>(obstacle.getCoordinates()) << "," << get<1>(obstacle.getCoordinates()) << ")" << endl;
    avatar.shift(3,3);
    cout << "New Avatar Coordinates: (" << get<0>(obstacle.getCoordinates()) << "," << get<1>(obstacle.getCoordinates()) << ")" << endl;



}