#include <iostream>

extern void print_pass_fail(char grade);

int main(){
    char grade; 
    //user input
    std::cout << "Type your grade: "; // Type a grade and press enter;
    std::cin >> grade; // Get user input from the keyboard;
    //output
    print_pass_fail(grade);
    
    return 0;
}