#include <iostream>
#include <string>

int main(){
    int x = 75;
    std::string binary = "";
    while ( x > 0){
        int remainder = x % 2;
        x = x/2;
        binary = std::to_string(remainder) + binary;
        
    }
    std::cout << binary << std::endl;
}