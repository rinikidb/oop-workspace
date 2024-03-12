#include <iostream>
using namespace std;
 
void changeValue(double* x){
    *x = 42;
}

void printArray(double* a, int n){
    for (int i = 0; i < n; i++){
        cout << *(a + i) << " ";
    }
}

double arrayMax(double* a, int n){
    double max = *(a + 1);
     for (int i = 0; i < n; i++){
        if (*(a + i) > max){
            max = *(a + i);
        }
    }
    return max;
}

double* dynamicArray(int n, double m){
    double* dynamic_array = new double[n];
    for (int i = 0; i < n; i++){
        dynamic_array[i] = m;
    }
    return dynamic_array;
}