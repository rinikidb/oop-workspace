#include <iostream>
using namespace std;

extern int *readNumbers();
extern bool equalsArray(int *numbers1,int *numbers2,int length);

int main(){
    int *allocated_array1 = readNumbers();
    int *allocated_array2 = readNumbers();
    int size = 10;
    equalsArray(allocated_array1,allocated_array2,size);
    delete[] allocated_array1;
    delete[] allocated_array2;
}
