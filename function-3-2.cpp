#include <iostream>
using namespace std;

int *readNumbers(){
    int *array = new int[10];
    for (int i = 0; i < 10; i++){
        cin >> array[i];
    }
    return array;
}

void printNumbers(int *numbers,int length){
    for (int i = 0; i < length; i++){
        cout << i << " " << numbers[i] << endl;
    }
}

bool equalsArray(int *numbers1,int *numbers2,int length){
    if(length > 1){
        int answer = 1;
        for(int i = 0; i < length; i++){
            if(numbers1[i]==numbers2[i]){
                answer = 1;
            }else{
                answer = 0;
                break;
            }
        }
        if(answer == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{ 
        return false;
    }
}

int *reverseArray(int *numbers1,int length){
    int *array = new int[length];
    for(int i = 0; i < length; i++){
        array[i] = numbers1[length-1-i];
    }
    return array;
}