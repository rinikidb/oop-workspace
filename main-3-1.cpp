#include <iostream>

extern bool is_fanarray(int array[], int n);

int main(){
    int array1[5] = {1,2,3,2,1};
    is_fanarray(array1, 5);
    //int array2[5] = {1,2,1,2,1};
    //is_fanarray(array2, 5);
}