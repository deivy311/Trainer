#include <iostream>
#include "math_operations.h"  // Include the custom math_operations header

int main() {
    int result;

    // Test Add function
    int num1 = 8, num2 = 3;
    Add(num1, num2, result);
    std::cout << "Addition of " << num1 << " and " << num2 << " is: " << result << std::endl;

    // Test Factorial function
    int num = 5;
    Factorial(num, result);
    std::cout << "Factorial of " << num << " is: " << result << std::endl;

    // Test Swap function
    int a = 15, b = 20;
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    Swap(a, b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}
