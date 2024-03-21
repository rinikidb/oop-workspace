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

int secondSmallestSum(int *numbers,int length){
    int size = 0;
    for (int a = 1; a < length+1; a++){
        size = size + a;
    }

    int array[size];
    int count = 0;
    for(int i = 0; i < length; i++){
        for(int j = i+1; j < length+1; j++){
            int sum = 0;
            for(int k = i; k < j; k++){
                sum = sum + numbers[k];
                array[count] = sum;
            }
            count++;
        }
    }

    /*for (int b = 0; b < size; b++){
        cout << array[b] << endl;
    }*/

    int smallest = array[0];
    for (int i = 0; i < size; i++){
        if (array[i] < smallest){
            smallest = array[i];
        }
    }
    int second_smallest;
    if (array[0] == smallest){
        second_smallest = array[1];
    }else{
        second_smallest = array[0];
    }
    for (int i = 0; i < size; i++){
        if (array[i] < second_smallest && array[i] > smallest){
            second_smallest = array[i];
        }
    }
    return second_smallest;
}