#include <iostream>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"
#include <tuple>
 
using namespace std;

int main(){

    tuple<int,int> pos1 = Utils::generateRandomPos(100,100);
    tuple<int,int> pos2 = Utils::generateRandomPos(100,100);   

    double dist = Utils::calculateDistance(pos1,pos2);

    cout << "Random position 1: (" << get<0>(pos1) << "," << get<1>(pos1) << ")" << endl;
    cout << "Random position 2: (" << get<0>(pos2) << "," << get<1>(pos2) << ")" << endl;

    cout << "Distance between them is: " << dist << " units" << endl;

    return 0;
}