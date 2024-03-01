#include <iostream>

extern double sum_even(double array[], int n);

int main(){
    double array1[5] = {1,5,3,4,2};
    sum_even(array1, 5);
}