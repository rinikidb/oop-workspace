#include <iostream>
// Minimum number in the array
int min_element(int array[], int n){
    if (n > 1){
        int min = array[0];
        for (int i = 1; i < n; i++){
            if (array[i] < min){
                min = array[i];
            }
        }
        return min;
        }
        return 0;
}