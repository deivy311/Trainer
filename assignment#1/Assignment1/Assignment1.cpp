#include <iostream>
#include "math.h"

int main()
{
    std::cout << "Assignment 1 Result: " << std::endl;

    int x = 20;
    int y = 10;
    int result;

    // Call Add
    Add(&x, &y);

    // Call AddVal
    AddVal(&x, &y, &result);

    // Call Swap
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(&x, &y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    // Call Factorial
    int num = 4;
    Factorial(&num, &result);

    return 0;
}
