#include <iostream>
#include "functions.hpp"

int main() {
    int a = 5, b = 3, result = 0;

    // Testing Add
    Add(a, b, result);
    std::cout << "Add: " << result << std::endl;

    // Testing Factorial
    int factorialResult;
    Factorial(a, factorialResult);
    std::cout << "Factorial of " << a << ": " << factorialResult << std::endl;

    // Testing Swap
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    Swap(a, b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
