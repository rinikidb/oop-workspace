#include <iostream>

extern double weighted_average(int array[], int n);

int main(){
    int array1[10] = {2,3,4,5,2,4,5,3,2,4};
    weighted_average(array1, 10);
}