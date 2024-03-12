#include <iostream>
#include "workshop.h"
using namespace std;

int main(){
    double a = 56;
    double* address = &a;
    //print old value
    cout << a << endl;
    changeValue(address);
    //print new value
    cout << a << endl;

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
    cout << "Max values of dynamic array is: " << arrayMax(dyn_arr, size) << endl;

    delete[] dyn_arr;
}
