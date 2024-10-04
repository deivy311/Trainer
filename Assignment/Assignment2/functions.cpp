#include "functions.hpp"

// Function to add two numbers and return the result through a reference parameter
void Add(int a, int b, int &result) {
    result = a + b;
}

// Recursive function to find the factorial of a number
void Factorial(int a, int &result) {
    if (a < 0) {
        result = 0; // Factorial is not defined for negative numbers
        return;
    }
    if (a == 0 || a == 1) {
        result = 1; // Base case
        return;
    }
    int temp = a; // Store the current value
    a--; // Decrease the value for recursion
    Factorial(a, result); // Recursive call
    result *= temp; // Multiply result with the current value
}

// Function to swap two numbers through reference arguments
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
