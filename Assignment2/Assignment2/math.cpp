#include "math.h"
#include <iostream>

void Add(int a, int b, int &result) {
    result = a + b;
    std::cout << "Sum is: " << result << std::endl;
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    
}

void Factorial(int a, int &result) {
    result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    std::cout << "Factorial of " << a << " is: " << result << std::endl;
}
