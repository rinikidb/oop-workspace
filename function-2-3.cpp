#include <iostream>
using namespace std;

bool is_palindrome(int integers[], int length){
    int answer = 0;
    if (length <= 0){
        return false;
    }
    else{
        for (int i = 0; i < length/2; i++){
            if (integers[i] == integers[length-1-i]){
                answer = 1;
            }else{
                answer = 0;
                break;
            }
        }
    }
    if (answer == 1){
        return true;
    }
    else{
        return false;
    }
}
int sum_array_elements(int integers[], int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += integers[i];
    }
    return sum;
} 
int sum_if_palindrome(int integers[], int length){
    
    if (!is_palindrome(integers, length)){
        return -2;
    }
    else{
        sum_array_elements(integers, length);
    }
    if (length <= 0){
        return -1;
    }
    else{
        return 0;
    }  
}
