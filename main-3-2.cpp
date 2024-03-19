#include <iostream>
using namespace std;

extern int *readNumbers();
extern bool equalsArray(int *numbers1,int *numbers2,int length);
extern int *reverseArray(int *numbers1,int length);

int main(){
    int *allocated_array1 = readNumbers();
    int size = 10;
    int *allocated_array2 = reverseArray(allocated_array1,size);
    int result = equalsArray(allocated_array1,allocated_array2,size);
    if (result==1){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }
    delete[] allocated_array1;
    delete[] allocated_array2;
}

