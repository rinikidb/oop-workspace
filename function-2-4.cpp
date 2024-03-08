#include <iostream>
using namespace std;

int array_min(int integers[], int length){
    int min = integers[0];
    if (length < 1){
        return -1;  
    }
    else{
        for (int i = 0; i < length; i++){
                if (integers[i] < min){
                    min = integers[0];
                }
        }
        return min;    
    }
}

int array_max(int integers[], int length){
    int max = integers[0];
    if (length < 1){
        return -1;
    }
    else{
        for (int i = 0; i < length; i++){
                if (integers[i] > max){
                    max = integers[0];
                }
        }
        return max;
    }
     
}

int sum_min_max(int integers[], int length){
    int max_element = array_max(integers, length);
    int min_element = array_min(integers, length);
    int sum = min_element + max_element;
    if (length < 1){
        return -1;
    }
    else{
        return sum;
    }
}