#include <iostream>
// Counts the number of even numbers between 1 and a number we supply (inclusive)
int count_evens(int number){
    int count = 0;
    if (number > 1){
        for (int i = 1; i < number+1; i++){
            if (i % 2 == 0){
                count += 1;
            }
        }
        return count;
    }
    return 0;
    
}