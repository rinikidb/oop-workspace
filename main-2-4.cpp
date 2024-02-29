#include <iostream>

extern bool is_ascending(int array[], int n);

int main(){
    int array[10] = {2,3,4,5,5,6,7,8,9,10};
    is_ascending(array, 10);
    return 0;
}