#include <iostream>
using namespace std;

extern int *readNumbers();
extern void hexDigits(int *numbers,int length);

int main(){
    int *allocated_array = readNumbers();
    int size = 10;
    hexDigits(allocated_array, size);
    delete[] allocated_array;
}