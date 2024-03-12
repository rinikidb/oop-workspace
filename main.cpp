#include <iostream>
using namespace std;

extern void changeValue(double* x);

int main(){
    double a = 56;
    double* address = &a;
    changeValue(address);
}