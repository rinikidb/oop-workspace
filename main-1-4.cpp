#include <iostream>

extern int sum_two_arrays(int array[], int secondarray[], int n);

int main(){
    
    int array[5] = {4,5,6,7,8};
    int secondarray[5] = {2,3,1,8,2};
    std::cout << "The sum of all the elements of both the arrays is: " << sum_two_arrays(array, secondarray, 5) << std::endl;
    
    return 0;
}