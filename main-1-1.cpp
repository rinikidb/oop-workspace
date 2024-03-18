#include <iostream>
using namespace std;

extern int *readNumbers();
extern void printNumbers(int *numbers,int length);

int main(){
    int *allocated_array = readNumbers();
    int size = 10;
    printNumbers(allocated_array, size);
}