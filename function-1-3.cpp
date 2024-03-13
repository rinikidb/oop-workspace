#include <iostream>
using namespace std;

double* duplicateArray(double* array, int size){
    double *dyn_array = new double[size];
    for (int i = 0; i < size; i++){
        dyn_array[i] = *(array + i);
    }
    return dyn_array;
}