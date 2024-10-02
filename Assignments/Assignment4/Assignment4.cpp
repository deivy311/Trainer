#include <iostream>
#include <string>
#include "convert.h"

// Main Function: This is the entry point for any C++ program. The main() function is where the program starts execution.:
int main() {
    std::string input;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::string upper = ToUpper(input);
    std::string lower = ToLower(input);

    std::cout << "Upper case: " << upper << std::endl;
    std::cout << "Lower case: " << lower << std::endl;

    return 0;
}
