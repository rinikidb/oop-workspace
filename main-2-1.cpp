#include <iostream>
using namespace std;

extern void print_binary_str(std::string decimal_number);

int main(){
    std::string decimal_number = "75";
    print_binary_str(decimal_number);
}