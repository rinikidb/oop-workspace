#include <iostream>
using namespace std;

int *readNumbers(){
    int *array = new int[10];
    for (int i = 0; i < 10; i++){
        cout << "Enter an integer: ";
        cin >> array[i];
    }
    return array;
}

void printNumbers(int *numbers,int length){
    for (int i = 0; i < length; i++){
        cout << i << " " << numbers[i] << endl;
    }
}