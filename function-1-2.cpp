#include <iostream>
using namespace std;

void modifyArray(double* array, int size, double value){
    for (int i = 0; i < size; i++){
        *(array + 1) = *(array + 1) + value;
    }
}
 