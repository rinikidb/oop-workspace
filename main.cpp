#include <iostream>
#include "workshop.h"
using namespace std;

void changeValue(double* x){
    *x = 42;
    cout << *x << endl;
}

void printArray(double* a, int n){
    cout << "Array elements: " << endl;
    for (int i = 0; i < n; i++){
        cout << *(a + i) <<endl;
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

int main(){
    double a = 56;
    double* address = &a;
    changeValue(address);

    double array[] = {1.0,2.0,3.0,4.0,5.0};
    //int size = sizeof(array)/sizeof(array[0]);
    int size = 5;
    double* array_address = &array[0];
    //print arrray values
    printArray(array_address, size);

    //print array max value
    cout << "Max value is: " << arrayMax(array_address, size) << endl;

    //value initialiser
    double arr_val = 9.0;

    //create dynamic array
    double* dyn_arr = dynamicArray(size, arr_val);
    //max of dynamic array but it will be same because all values are same
    cout << "Max valus of dunamic array is: " << arrayMax(dyn_arr, size) << endl;

    delete[] dyn_arr;
}
