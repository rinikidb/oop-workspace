#include <iostream>
#include <string>

void print_binary_str(std::string decimal_number){
    int x = stoi(decimal_number);
    std::string binary = "";
    while ( x >= 2){
        int remainder = x % 2;
        binary = std::to_string(remainder) + binary;
        x = x/2;
    }
    binary = std::to_string(char (1)) + binary;
    std::cout << binary << std::endl;
}