#include <iostream>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"

using namespace std;

int main(){

    tuple<int,int> position1 = Utils::generateRandomPos(100,100);
    tuple<int,int> position2 = Utils::generateRandomPos(100,100);

    cout << "Position 1 is: (" << get<0>(position1) << "," << get<1>(position1) << ")" << endl;
    cout << "Position 2 is: (" << get<0>(position2) << "," << get<1>(position2) << ")" << endl;

    cout << "The distance between these two positions is: " << Utils::calculateDistance(position1,position2) << " units" << endl;

    return 0;
}