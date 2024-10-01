#include <iostream>
#include "functions.hpp"

int main() {
    int a = 5, b = 3, result = 0;

    // Testing Add
    std::cout << "Add: " << Add(&a, &b) << std::endl;

    // Testing AddVal
    AddVal(&a, &b, &result);
    std::cout << "AddVal: " << result << std::endl;

    // Testing Swap
    std::cout << "Before Swap: a = " << a << ", b = " << b << std::endl;
    Swap(&a, &b);
    std::cout << "After Swap: a = " << a << ", b = " << b << std::endl;

    // Testing Factorial
    int factorialResult;
    Factorial(&a, &factorialResult);
    std::cout << "Factorial of 5: " << factorialResult << std::endl;

    return 0;
}
