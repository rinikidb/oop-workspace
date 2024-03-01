#include <iostream>

bool is_fanarray(int array[], int n){
    int answerasc = 0;
    int answerpal = 0;
    if (n > 1){
        if (n % 2 == 0){
            for (int i = 0; i < n/2; i++){
                if (array[i] <= array[i+1]){
                    answerasc = 1;
                }else{
                    answerasc = 0;
                    break;
                }
            }
            if (answerasc == 1){
                for (int i = 0; i < n/2; i++){
                    if (array[i] == array[4-i]){
                        answerpal = 1;
                    }else{
                        answerpal = 0;
                        break; 
                    }
                }
            }        
        }
        else {
            for (int i = 0; i < (n-1)/2; i++){
                if (array[i] <= array[i+1]){
                    answerasc = 1;
                }else{
                    answerasc = 0;
                    break;
                }
            }
            if (answerasc == 1){
                for (int i = 0; i < (n-1)/2; i++){
                    if (array[i] == array[4-i]){
                        answerpal = 1;
                    }else{
                        answerpal = 0; 
                        break; 
                    }
                }
            }        
        }
        
        if (answerpal == 1){
            std::cout << "This given array is a palindrome." << std::endl;
            return 1;
        }else{
            std::cout << "This given array is not a palindrome." << std::endl;
            return 0;
        }
        
    }
    else {
        return 0;
    }
}