#include <iostream>
using namespace std;

double* dynamicArray(int n, double m){
    double* dynamic_array = new double[n];
    for (int i = 0; i < n; i++){
        dynamic_array[i] = m;
    }
    return dynamic_array;
}