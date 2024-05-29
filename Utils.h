#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

class Utils{
    public:
        static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight){
            int x = rand() % gridWidth;
            int y = rand() % gridHeight;
            std::tuple<int, int> randomPos = make_tuple(x,y);
            return randomPos;
        }
        static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2){
            int x1 = get<0>(pos1);
            int y1 = get<1>(pos1);
            int x2 = get<0>(pos2);
            int y2 = get<1>(pos2);

            double dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
            return dist;

        }
};


#endif