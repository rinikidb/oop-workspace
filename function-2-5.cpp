#include <iostream>
#include <string>

bool is_descending(int array[], int n){
    int answer = 0;
    if (n > 0){
        for (int i = 0; i < n; i++){
            if (array[i] >= array[i+1]){
                answer = 1;
            }else{
                break;
            }
        }
        if (answer == 1){
            return 1;
        }else{
            return 0;
        }
    }
    else{
        return 0;
    }
} 