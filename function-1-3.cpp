#include <iostream>
// Returns the number of elements in an array that are equal to a given parameter
int num_count(int array[], int n, int number) {
    int sum = 0;
    if (n > 1){
        for (int i = 0; i < n; i++){
            if (array[i] == number){
                sum += 1;
            }
        }
        return sum;
    }
    
    return 0;
    
}