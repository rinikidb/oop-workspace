#include <iostream>
using namespace std;

extern double arrayMin(double* array, int size);

int main(){
    double array[] = {1.2, 2.3, 3.4, 4.5, 0.9};
    int n = 5;
    double *array_pointer = &array[0];
    cout << arrayMin(array_pointer, n) << endl;
}