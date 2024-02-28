#include <iostream>
// Returns the average of all elements in an integer array
double array_mean(int array[], int n){
    double sum = 0;
    if (n > 1){
        for (int i = 0; i < n; i++){
            sum += array[i];
        }
        double mean = sum/n;
        return mean;
    }
    
    return 0;
    
}