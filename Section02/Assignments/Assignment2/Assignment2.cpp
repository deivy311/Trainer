#include <iostream>
using namespace std;

// Function to add two numbers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Function to find the factorial of a number and return it through a reference parameter
void Factorial(int a, int &result) {
    result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
}

// Function to swap two numbers using reference arguments
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10, result;

    // Example for Add
    Add(x, y, result);
    cout << "Add: " << result << endl;

    // Example for Factorial
    Factorial(x, result);
    cout << "Factorial of " << x << ": " << result << endl;

    // Example for Swap
    Swap(x, y);
    cout << "After Swap: x = " << x << ", y = " << y << endl;

    return 0;
}
