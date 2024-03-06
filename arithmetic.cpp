#include <iostream>
using namespace std;

int addBinary(int num1, int num2){
    int sum = num1 + num2;
    return sum;
}

int subtractBinary(int num1, int num2){
    int difference = num1 - num2;
    return difference;
}

 int shiftLeft(int num1, int n){
    int x = num1 << n;
    return x;
}

int shiftRight(int num1, int n){
    int x = num1 >> n;
    return x;
}

int main(){
    int number1 = 0b1001011;
    int number2 = 0b1100100;
    int shiftPlaces = 2;

    //calling to add
    cout << addBinary(number1, number2) << endl;
    //calling subtract
    cout << subtractBinary(number2, number1) << endl;
    //shifting to left
    cout << shiftLeft(number1, shiftPlaces) << endl;
    //shifting to right 
    cout << shiftRight(number2, shiftPlaces) << endl;

}