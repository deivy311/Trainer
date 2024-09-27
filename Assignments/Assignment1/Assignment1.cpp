#include <iostream>
#include "math_operations.h"

int main(int argc, char *argv[]) {
    int x = 3, y = 5, result = 0;

    // Add two numbers and return the sum
    std::cout << "Add(" << x << ", " << y << ") = " << Add(&x, &y) << std::endl;

    // Example for AddVal function
    AddVal(&x , &y, &result);
    std::cout << "AddVal(" << x << ", " << y << ") -> result = " << result << std::endl;

    // Example to Swap the value of two integers
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(&x, &y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    // Example for Factorial function
    int num = 4;
    Factorial(&num, &result);
    std::cout << "Factorial (" << num << ") = " << result << std::endl;

    return 0;
}
