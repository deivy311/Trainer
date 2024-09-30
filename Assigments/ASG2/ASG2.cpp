#include <iostream>
#include "functions.h"

int main() {
    int x = 5, y = 3;
    int sum = 0, fact = 0;

    // Using Add function
    Add(x, y, sum);
    std::cout << "Summation of " << x << " and " << y << " is: " << sum << std::endl;

    // Using Factorial function
    Factorial(x, fact);
    std::cout << "Factorial of " << x << " is: " << fact << std::endl;

    // Using Swap function
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(x, y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
