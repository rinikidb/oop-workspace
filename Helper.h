#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

class Helper{
    public: 
        static tuple<int, int> generateRandomCoordinates(int gridWidth, int gridHeight){
            int x = rand() % gridWidth;
            int y = rand() % gridHeight;

            tuple<int, int> randomPos = make_tuple(x,y);

            return randomPos;

        }
        static double calculateDistance(std::tuple<int, int> coords1, std::tuple<int, int> coords2){
            int x1 = get<0>(coords1);
            int y1 = get<1>(coords1);
            int x2 = get<0>(coords2);
            int y2 = get<1>(coords2);

            double dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
            
            return dist;

        }
};

#endif