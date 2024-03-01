#include <iostream>

int median_array(int array[], int n){
    if (n > 1){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++) { 
                if(array[i]>array[j]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        if (n % 2 != 0){
            return array[(n+1)/2];
        }
        else {
            return 0;
        }
    }
    else{
        return 0;
    }
}