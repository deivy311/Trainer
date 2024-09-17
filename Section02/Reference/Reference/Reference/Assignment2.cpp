#include <iostream>

// Function to add two numbers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Function to calculate the factorial of a number and return the result through a reference parameter
void Factorial(int a, int &result) {
    result = 1;  
    for (int i = 2; i <= a; ++i) {
        result *= i;  
    }
}

// Function to swap two numbers through reference arguments
void Swap(int &a, int &b) {
    int temp = a;  
    a = b;         
    b = temp;      
}

int main() {
    int x = 5, y = 3, result = 0;

    // Example for Add function
    Add(x, y, result);
    std::cout << "Add(" << x << ", " << y << ") = " << result << std::endl;

    // Example for Factorial function
    int num = 4;
    Factorial(num, result);
    std::cout << "Factorial(" << num << ") = " << result << std::endl;

    // Example for Swap function
    std::cout << "Before Swap: x = " << x << ", y = " << y << std::endl;
    Swap(x, y);
    std::cout << "After Swap: x = " << x << ", y = " << y << std::endl;

    return 0;
}
