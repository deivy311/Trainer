#include <iostream>
#include "math.h"


int main() {
    int a = 3, b = 7, res = 0;

    Add(a, b, res);
    std::cout << "Add two numbers and return the result through a reference parameter: " << res << std::endl;

    Factorial_recursive(a, res);
    std::cout << "Find factorial of a number and return that through a reference parameter: " << res << std::endl;
    
    Swap(a, b);
    std::cout << "Swap two numbers through reference arguments. a = " << a << ", b = " << b << std::endl;

    return 0;
}
