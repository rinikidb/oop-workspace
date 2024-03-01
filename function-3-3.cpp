#include <iostream>

double weighted_average(int array[], int n){
    if (n > 1){
        int sum = 0;
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < n; j++){
                if (array[j]==array[i]){
                    count += 1;
                }
            }
            sum += (array[i]*count);
        }
        int avg = sum/n;
        return sum;
    }
    else {
        return 0;
    }
}