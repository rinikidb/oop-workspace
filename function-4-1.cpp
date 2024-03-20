#include <iostream>
using namespace std;

int *readNumbers(){
    int *array = new int[4];
    for (int i = 0; i < 4; i++){
        cin >> array[i];
    }
    return array;
}

void printNumbers(int *numbers,int length){
    for (int i = 0; i < length; i++){
        cout << i << " " << numbers[i] << endl;
    }
}

int secondSmallestSum(int *numbers,int length){
    int min_sum = numbers[0] + numbers[1];
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            int sum = numbers[i] + numbers[j+1];
            if (sum < min_sum){
                min_sum = sum; 
            }
        }
    }
    return min_sum;
}