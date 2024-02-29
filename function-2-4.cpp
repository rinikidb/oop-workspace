#include <iostream>
#include <string>

bool is_ascending(int array[], int n){
    std::string answer = "yes";
    if (n > 0){
        for (int i = 0; i < n; i++){
            if (array[i] <= array[i+1]){
                answer = "yes";
            }
            else{
                answer = "no";
            }
            if (answer == "no"){
                break;
            }
        }
        if (answer == "yes"){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if (n < 0){
        return 0;
    }
}