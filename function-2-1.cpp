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

void hexDigits(int *numbers,int length){
    for(int i = 0; i < length; i++){
        int rem = numbers[i]%16;
        if (rem < 10){
            cout << i << " " << numbers[i] << " " << rem << endl;
        }
        else{
            char hex_digit;
            switch(rem){
                case 10:
                    hex_digit = 'A';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                case 11:
                    hex_digit = 'B';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                case 12:
                    hex_digit = 'C';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                case 13:
                    hex_digit = 'D';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                case 14:
                    hex_digit = 'E';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                case 15:
                    hex_digit = 'F';
                    cout << i << " " << numbers[i] << " " << hex_digit << endl;
                    break;
                default:
                    break;
            }
        }
    }
}