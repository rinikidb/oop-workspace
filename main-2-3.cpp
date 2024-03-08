#include <iostream>
using namespace std;

extern bool is_palindrome(int integers[], int length);
extern int sum_array_elements(int integers[], int length);
extern int sum_if_palindrome(int integers[], int length);

int main(){
    int array[] = {1,2,0,2,1};
    int length = sizeof(array)/sizeof(array[0]);
    cout << sum_if_palindrome(array, length) << endl;
}