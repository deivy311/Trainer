#include <iostream>
#include "functions.hpp"

int main() {
    // Testing string conversion
    std::string original = "Hello, World!";
    std::cout << "Original: " << original << std::endl;
    std::cout << "Uppercase: " << ToUpper(original) << std::endl;
    std::cout << "Lowercase: " << ToLower(original) << std::endl;

    // Testing Add
    int result = 0;
    Add(5, 3, result);
    std::cout << "Add: " << result << std::endl;

    // Testing Factorial
    int factorialResult;
    Factorial(5, factorialResult);
    std::cout << "Factorial of 5: " << factorialResult << std::endl;

    // Testing Swap
    int a = 10, b = 20;
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    Swap(a, b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
