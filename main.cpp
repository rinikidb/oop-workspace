#include <iostream>

// The `extern` keyword tells the compiler that the count function exists,
// but will be implemented somewhere else
extern int count(int[], int);

int main() {
    //test cases
    //1. array[5] = {1,2,6,7,8}; expected output: The number is: 1
    //2. array[6] = {2,4,6,7,9,10}; expected output: The number is: 4
    int array[5] = {4,5,6,7,8};
    std::cout << "The number is: " << count(array, 5) << std::endl;
    
    return 0;
}