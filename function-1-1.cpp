#include <iostream>
using namespace std;

double arrayMin(double* array, int size){
    double min = *(array);
    for (int i = 0; i < size; i++){
        if (*(array + i) < min){
            min = *(array + i);
        }
    }
    return min;
}