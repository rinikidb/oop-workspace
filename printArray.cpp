#include <iostream>
using namespace std;

void printArray(double* a, int n){
    cout << "Array elements: " << endl;
    for (int i = 0; i < n; i++){
        cout << *(a + i) <<endl;
    }
}
