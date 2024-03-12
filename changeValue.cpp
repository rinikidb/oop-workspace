#include <iostream>
using namespace std;

void changeValue(double* x){
    *x = 42;
    cout << *x << endl;
}