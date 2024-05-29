#include <iostream>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"
#include "Explosion.h"
#include "Mine.h"
#include "Ship.h"
#include <tuple>
 
using namespace std;

int main(){

    Ship ship(7,8);
    cout << "Original position: (" << get<0>(ship.getPos()) << "," << get<1>(ship.getPos()) << ")" << endl;
    ship.move(3,3);
    cout << "New position: (" << get<0>(ship.getPos()) << "," << get<1>(ship.getPos()) << ")" << endl;

    Mine mine(5,6);
    cout << "Original mine type: " << mine.getType() << endl;
    Explosion explosion = mine.explode();
    cout << "New mine type after explosion: " << mine.getType() << endl; 

    cout << "Original ship type: " << ship.getType() << endl;
    explosion.apply(ship);
    cout << "New ship type after explosion: " << ship.getType() << endl;


    return 0;
}