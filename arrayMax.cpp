#include <iostream>
using namespace std;
 
double arrayMax(double* a, int n){
    double max = *(a + 1);
     for (int i = 0; i < n; i++){
        if (*(a + i) > max){
            max = *(a + i);
        }
    }
    return max;
}