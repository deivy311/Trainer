#include <iostream>
#include "functions.h"

int main() {
    int x = 5, y = 3;
    int sum = 0, factLoop = 0, factRecursive = 0;

    // Using Add function
    std::cout << "Summation of " << x << " and " << y << " is: " << Add(&x, &y) << std::endl;

    // Using AddVal function
    AddVal(&x, &y, &sum);
    std::cout << "Summation of " << x << " and " << y << " using AddVal is: " << sum << std::endl;

    // Using Swap function
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(&x, &y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    // Using FactorialLoop function
    FactorialLoop(&x, &factLoop);
    std::cout << "Factorial of " << x << " using loop is: " << factLoop << std::endl;

    // Using FactorialRecursive function
    FactorialRecursive(&x, &factRecursive);
    std::cout << "Factorial of " << x << " using recursion is: " << factRecursive << std::endl;

    return 0;
}
