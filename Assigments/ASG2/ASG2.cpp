// Implement the following functions ((Reference))

#include <iostream>

// Function to add two integers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Function to calculate the factorial of a number and return the result through a reference parameter
void Factorial(int a, int &result) {
    result = 1;
    for (int i = 1; i <= a; ++i) {
        result *= i;
    }
}

// Function to swap two integers using reference arguments
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2, result = 0;

    // Using Add function
    Add(x, y, result);
    std::cout << "Sum of " << x << " and " << y << " is: " << result << std::endl;

    // Using Factorial function
    Factorial(x, result);
    std::cout << "Factorial of " << x << " is: " << result << std::endl;

    // Using Swap function
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(x, y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
