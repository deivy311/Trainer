#include <iostream>

//Add two numbers and return the result through a reference parameter
void Add(int a,int b, int &result)
{
    result = a + b;
}
//Find factorial of a number and return that through a reference parameter
void Factorial(int a, int &result)
{
    result = 1;
    for (int i = 1; i <= a; ++i) {
        result *= i;
    }
}
//Swap two numbers through reference arguments
void Swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int main() {
    int x = 2, y = 1, result = 0;
    std::cout << "Assignment2-Reference " << std::endl;

    // Add
    Add(x, y, result);
    std::cout << "Add(2, 1): " << result << std::endl;

    // Factorial
    Factorial(x, result);
    std::cout << "Factorial(2): " << result << std::endl;

    // Swap
    Swap(x, y);
    std::cout << "Swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}