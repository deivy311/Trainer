#include <iostream>

void Add(int a, int b, int &result) {
    result = a + b;
}

void Factorial(int a, int &result) {
    result = 1;
    for (int i = 1; i <= a; ++i) {
        result *= i;
    }
}

void Swap(int &a, int &b) {
    int temp = a; 
    a = b;
    b = temp;
}

int main() {
    int a = 3, b = 7, res = 0;

    Add(a, b, res);
    std::cout << "Add two numbers and return the result through a reference parameter: " << res << std::endl;

    Factorial(a, res);
    std::cout << "Find factorial of a number and return that through a reference parameter: " << res << std::endl;
    
    Swap(a, b);
    std::cout << "Swap two numbers through reference arguments. a = " << a << ", b = " << b << std::endl;

    return 0;
}
