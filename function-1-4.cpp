#include <iostream>
//Returns the sum of two arrays as an integer (of equal size)
int sum_two_arrays(int array[], int secondarray[], int n){
    int sum = 0;
    if ( n > 1){
        for (int i = 0; i < n; i++){
        sum += array[i] + secondarray[i];
        }
    return sum;
    }
    return 0;
}