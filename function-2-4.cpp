#include <iostream>
using namespace std;

int array_min(int integers[], int length){
    int min = integers[0];
    if (length < 1){
        for (int i = 0; i < length; i++){
            if (integers[i] < min){
                min = integers[0];
            }
        }
        return min; 
    }
    else{
        return -1;
    }
}

int array_max(int integers[], int length){
    int max = integers[0];
    if (length < 1){
        for (int i = 0; i < length; i++){
            if (integers[i] > max){
                max = integers[0];
            }
        }
        return max;
    }
    else{
        return -1;
    }
     
}

int sum_min_max(int integers[], int length){
    if (length < 1){
        return -1;
    }
    else{
        int max_element = array_max(integers, length);
        int min_element = array_min(integers, length);
        return (min_element + max_element);
    }
}