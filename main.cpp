#include <iostream>

// The `extern` keyword tells the compiler that the count function exists,
// but will be implemented somewhere else
extern int count(int[], int);

int main() {
    //test case1
    int array[5] = {4,5,6,7,8};
    std::cout << "The number is: " << count(array, 5) << std::endl;

    //test case2
    int array1[6] = {4,2,6,7,8,9};
    std::cout << "The number is: " << count(array1, 6) << std::endl;
    
    //test case3
    int array2[5] = {1,5,6,7,9};
    std::cout << "The number is: " << count(array2, 5) << std::endl;
    
    return 0;
}