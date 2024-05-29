#include <iostream>
#include "GameSession.h"

using namespace std;

int main(){

    GameSession gameSession;
    gameSession.initGameSession(3,3,10,10);

    vector<GridUnit*>& grid = gameSession.getGrid();

    for(auto obj:grid){
        cout << "obj type: " << obj->getEntity() << endl;
        cout << "obj cooardinates: (" << get<0>(obj->getCoordinates()) << "," << get<1>(obj->getCoordinates()) << ")" << endl;
    }

    gameSession.gameCycle(5,1.5);


}