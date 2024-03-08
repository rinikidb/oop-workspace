#include <iostream>
using namespace std;

extern int binary_to_int(int binary_digits[], int number_of_digits);

int main(){
    int binary[] = {1,0,0,1,0,1,1};
    int num_digits = sizeof(binary)/sizeof(binary[0]);
    cout << binary_to_int(binary, num_digits) << endl;
}