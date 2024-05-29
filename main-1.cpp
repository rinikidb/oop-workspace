#include <iostream>
#include "GridUnit.h"
#include "Helper.h"

using namespace std;

int main(){

    GridUnit gridUnit(3,4,'R');
    cout << "Original coords: (" << get<0>(gridUnit.getCoordinates()) << "," << get<1>(gridUnit.getCoordinates()) << ")" << endl;
    cout << "Original entity: " << gridUnit.getEntity() << endl;

    gridUnit.setCoordinates(5,6);
    cout << "New coords: (" << get<0>(gridUnit.getCoordinates()) << "," << get<1>(gridUnit.getCoordinates()) << ")" << endl;
    gridUnit.setEntity('S');
    cout << "New entity: " << gridUnit.getEntity() << endl;

    tuple<int, int> pos1 = Helper::generateRandomCoordinates(10,10);
    tuple<int, int> pos2 = Helper::generateRandomCoordinates(10,10);

    double dist = Helper::calculateDistance(pos1,pos2);

    cout << "The distance between the two positions is: " << dist << " units" << endl; 



    return 0;
}