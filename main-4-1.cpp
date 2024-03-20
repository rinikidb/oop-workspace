#include <iostream>
using namespace std;

extern int *readNumbers();
extern int secondSmallestSum(int *numbers,int length);

int main(){
    int *allocated_array = readNumbers();
    int size = 4;
    cout << secondSmallestSum(allocated_array, size) << endl;
    delete[] allocated_array;
}