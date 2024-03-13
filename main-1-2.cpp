#include <iostream>
using namespace std;

extern void modifyArray(double* array, int size, double value);

int main(){
    double array[] = {1.2, 2.3, 3.4, 4.5, 0.9};
    int n = 5;
    double num = 2.5;
    double *array_pointer = &array[0];
    modifyArray(array_pointer, n, num);
}