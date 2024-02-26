#include <iostream>
// Returns the total count of even numbers in the given array
int count(int array[], int n) {
    // evcount is the variable which shall keep count of the even numbers
    int evcount = 0;
    for (int i = 0; i < n; i++) {
        if (array[i]%2 == 0) {
            evcount += 1;
        }
    }

    return evcount;
}