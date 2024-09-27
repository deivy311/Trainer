#include "math.h"
#include <iostream>

void Add(const int a, const int b, int &result) {
    result = a + b;
    std::cout << "Sum is: " << result << std::endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    
}

void Factorial(int a, int &result)
{ // Generate the factorial of a number and return that through the second pointer argument

    if (a <= 1)
    {
        result = 1;  // Base case: factorial of 0 or 1 is 1
    }
    else
    {
        int temp = a - 1;
        Factorial(temp, result);  // Recursive call
        result = result * (a);  // Multiply by current value of a
    }
}