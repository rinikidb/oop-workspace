#include <iostream>

extern bool is_ascending(int array[], int n);

int main(){
    int array[10] = {2,3,6,8,5,4,2,9,0,1};
    is_ascending(array, 10);
    return 0;
}