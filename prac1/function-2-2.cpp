#include <iostream>
// Maximum number in the array
int max_element(int array[], int n){
    if (n > 1){
        int max = array[0];
        for (int i = 1; i < n; i++){
            if (array[i] > max){
                max = array[i];
            }
        }
        return max;
        }
        return 0;
}