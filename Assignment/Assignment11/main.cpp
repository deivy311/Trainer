#include <iostream>
#include "functions.hpp"  // Include the header file

int main() {
    // Test the FindAll function
    std::string target = "Hello, hello, HELLO!";
    std::string search_string = "hello";

    // Case-insensitive search
    std::vector<int> indices = FindAll(target, search_string, Case::INSENSITIVE);
    std::cout << "Case-insensitive search results: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Case-sensitive search
    indices = FindAll(target, search_string, Case::SENSITIVE);
    std::cout << "Case-sensitive search results: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;

    // Test the recursive factorial function
    int number = 5;
    int fact = Factorial(number);
    std::cout << "Factorial of " << number << " is: " << fact << std::endl;

    return 0;
}
