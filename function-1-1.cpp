#include <iostream>
using namespace std;
int sum_diagonal(int array[4][4]){
    int sum = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (i == j){
                sum += array[i][j];
            }
        }
    }
    return sum;
}