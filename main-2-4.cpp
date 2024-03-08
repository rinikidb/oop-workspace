#include <iostream>
using namespace std;

extern int array_max(int integers[], int length);
extern int array_min(int integers[], int length);
extern int sum_min_max(int integers[], int length);

int main(){
    int array[] = {1,2,3,4,5};
    int size = sizeof(array)/sizeof(array[0]);
    sum_min_max(array, size);
}