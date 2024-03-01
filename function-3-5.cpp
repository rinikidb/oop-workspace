#include <iostream>

double sum_even(double array[], int n){
    if (n > 1){
        int sum;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                sum += array[i];
            }
        }
        return sum;
    }
    else {
        return 0;
    }
}