#include <iostream>
using namespace std;
int is_identity(int array[10][10]){
    int answer = 0;
    for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (i == j){
                    if (array[i][j] == 1){
                        answer += 1;
                    }
                }
                /*
                else{
                    if (array[i][j] == 0){
                        answer = 1;
                    }else{
                        answer = 0;
                    }
                }
                */
            }
    }
    
    if (answer == 10){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (i != j){
                    if (array[i][j] == 0){
                        answer += 1;
                    }
                }
            }
        }
        
    }
    if (answer == 100){
        return 1; 
    }  
    else{
        return 0;
    }
}   