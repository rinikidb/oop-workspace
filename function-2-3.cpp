#include <iostream>

void two_five_nine(int array[], int n){
    if (n > 1){
        int sum2 = 0;
        int sum5 = 0;
        int sum9 = 0;
        int element;
        for (int i = 0; i < n; i++){
            element = array[i];
            switch(element){
                case 2:
                    sum2 += 1;
                    break;
                case 5:
                    sum5 += 1;
                    break;
                case 9:
                    sum9 += 1;
                    break;
                default:
                    break;
            }   
                         
        }
        std::cout << "2:" << sum2 << "\n" << std::endl;
        std::cout << "5:" << sum5 << "\n" << std::endl;
        std::cout << "9:" << sum9 << "\n" << std::endl;
    }
    else if (n < 1){
        std::cout << "Invalid input for n." << std::endl; 
    } 
}