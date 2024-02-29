#include <iostream>

bool is_fanarray(int array[], int n){
    int answerasc = 0;
    int answerpal = 0;
    if (n > 1){
        for (int i = 0; i < (n-1)/2; i++){
            if (array[i] <= array[i+1]){
                answerasc = 1;
            }else{
                break;
            }
        }
        if (answerasc == 1){
            for (int i = 0; i < (n-1)/2; i++){
                if (array[i] == array[4-i]){
                    answerpal = 1;
                }else{
                    break; 
                }
            }
        }        
        
        if (answerpal == 1){
            return 1;
        }
        else{
            return 0;
        }  
    }
    else {
        return 0;
    }
}