#include <iostream>

extern void two_five_nine(int array[], int n);

int main(){
    int array[10] = {2,2,5,5,2,5,5,9,9,9};
    two_five_nine(array, 10);
    return 0;
}