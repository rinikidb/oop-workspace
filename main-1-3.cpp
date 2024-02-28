#include <iostream>

extern int num_count(int array[], int n, int number);

int main(){
    //test cases
    //1. array[5] = {2,2,2,2,2}; number = 2; expected output: The number is: 5
    //2. array[6] = {2,4,6,4,9,4}; number = 4; expected output: The number is: 3
    //3. array[] is any array and where n=-1 (number accordingly); expected output: The number is: 0
    int array[5] = {2,2,2,2,2};
    std::cout << "The number of elements in an array that are equal to the given parameter is: " << num_count(array, 5, 2) << std::endl;
    
    return 0;
}