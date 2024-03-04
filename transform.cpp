#include <iostream>
#include <string>

int main(){
    int x = 75;
    std::string binary = "";
    while ( x >= 2){
        int remainder = x % 2;
        binary = std::to_string(remainder) + binary;
        x = x/2;
    }
    binary = std::to_string(char (1)) + binary;
    std::cout << binary << std::endl;
}