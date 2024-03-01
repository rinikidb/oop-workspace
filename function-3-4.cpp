#include <iostream>

void print_pass_fail(char grade){
    switch(grade){
        case 'A':
            std::cout << "Pass \n" << std::endl;
            break;
        case 'B':
            std::cout << "Pass \n" << std::endl;
            break;
        case 'C':
            std::cout << "Pass \n" << std::endl;
            break;
        case 'D':
            std::cout << "Fail \n" << std::endl;
            break;
        case 'E':
            std::cout << "Fail \n" << std::endl;
            break;
        default:
            std::cout << "Nothing \n" << std::endl;
            break;
    }
}