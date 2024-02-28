#include <iostream>

extern int array_sum(int array[], int n);

int main(){
    //test cases
    //1. array[5] = {1,2,6,7,8}; expected output: The number is: 30
    //2. array[6] = {2,4,6,7,9,10}; expected output: The number is: 38
    //3. array[] = { } where n=-1; expected output: The number is: 0
    int array[5] = {4,5,6,7,8};
    std::cout << "The sum of all the elements in the array is: " << array_sum(array, 5) << std::endl;
    
    return 0;
}