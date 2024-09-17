#include <iostream>
#include "math.h"

int main() {
    int x = 5, y = 10, result;

    // Call Add
    Add(x, y, result);

    // Call Swap
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(x, y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    // Call Factorial
    int num = 2;
    Factorial(num, result);

    return 0;
}
