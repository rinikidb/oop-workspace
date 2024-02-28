#include <iostream>

extern int count_evens(int number);

int main(){
    int number; 
    //user input
    std::cout << "Type a number: "; // Type a number and press enter;
    std::cin >> number; // Get user input from the keyboard;
    //output
    std::cout << "The number of even numbers is: " << count_evens(number) << std::endl;
    
    return 0;
}